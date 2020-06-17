#include "uid.h"

const ilrd_uid_t BAD_UID = {0, 0};

/******************************* -- CREATE -- *********************************/
ilrd_uid_t UIDCreate(void)
{
	static size_t counter = 0;
	
	ilrd_uid_t new_uid = {0,0};
	
	/*initialized*/
	new_uid.uid = time(NULL);
	new_uid.counter = ++counter;

	return new_uid;
}

/****************************** -- IS SAME -- *********************************/
int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2)
{
	return (uid1.uid == uid2.uid && uid1.counter == uid2.counter);
}
