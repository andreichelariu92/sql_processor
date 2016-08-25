#ifndef REFERENCE_COUNTER_H
#define REFERENCE_COUNTER_H

/**
 * \brief
 * Structure that represents a reference counter.
 * A pointer to this structure is used by the client
 * code to manage a resource.
 */
struct ref_counter;

/**
 * \brief
 * Alias for cleanup function. This function is used
 * by the ref_counter to cleanup the resource after the
 * count has reached zero.
 */
typedef int(*cleanup_func)(void*);

/**
 * \brief RC_Create
 * Create a reference counter for the given resource.
 *
 * \param resource
 * Pointer to a resource that will be manged.
 *
 * \param f
 * A pointer to a cleanup function. This function will be
 * used to cleanup the resource when the counter has reached
 * zero.
 *
 * \return
 * A pointer to a ref_counter struct. In case of error,
 * NULL will be returned.
 */
struct ref_counter* RC_Create(void* resource, cleanup_func f);

/**
 * \brief RC_Get
 * Returnes the address of the resource that is managed
 * by the resource counter. Do not attempt to free this
 * memory. Every call to RC_Get should be paired to a call
 * to RC_Release.
 *
 * \param r
 * Pointer to a ref_counter struct.
 *
 * \return
 * The resource that is managed by the resource counter.
 */
void* RC_Get(struct ref_counter* r);

/**
 * \brief RG_Release
 * Decrease the reference count of the resource. This function
 * should be paired with the RC_Get function. If the count reaches
 * zero, the the cleanup function is called.
 *
 * \param r
 * Pointer to a ref_counter structure.
 *
 * \return
 * The value returned by the cleanup function or zero in case there are
 * no other active references to the resource.
 */
int RC_Release(struct ref_counter* r);

/**
 * \brief RC_Distroy
 * Distroys the reference counter. In case the count is higher than zero,
 * it also calls the cleanup function.
 *
 * \param r
 * Pointer to a ref_count structure.
 *
 * \return
 * The value returned by the cleanup function or zero in case there are
 * no other active references to the resource.
 */
int RC_Distroy(struct ref_counter* r);
#endif // REFERENCE_COUNTER_H
