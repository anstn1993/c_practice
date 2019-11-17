#include "userdata.h"
#include "user_sorter.h"

int compare_age_id(const void* p0, const void* p1)/* p0이 앞에 와야 한다면 음수 반환, p0이 뒤에 와야 한다면 양수 반환, 같으면 id비교*/
{
	const userdata_t* user0 = p0;
	const userdata_t* user1 = p1;

	if (user0->age == user1->age) {
		return user0->id - user1->id;/* 음수면 p0이 앞, 양수면 p0이 뒤 */
	}

	return user0->age - user1->age;/* 젊은 사람이 앞에 위치 */


}
int compare_age_desc_sex(const void* p0, const void* p1)
{
	const userdata_t* user0 = p0;
	const userdata_t* user1 = p1;

	if (user0->age == user1->age) {
		return user0->sex - user1->sex;/* 음수면 p0이 앞, 양수면 p0이 뒤 */
	}

	return user1->age - user0->age;/* 젊은 사람이 뒤에 위치(내림차순) */
}