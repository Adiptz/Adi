/**************************
 *    Author  : Adi       *
 *    Reviwer : Daya      *
 *    Status  : Sent      *
 **************************/
 
#include <assert.h> /* assert */

#include "uid.h"


void Create_IsSame_test()
{
	ilrd_uid_t uid1 = UIDCreate();
	ilrd_uid_t uid2 = UIDCreate();
	
	assert(!UIDIsSame(uid1, uid2));
}

int main()
{
	Create_IsSame_test();
	
	return 0;
}
