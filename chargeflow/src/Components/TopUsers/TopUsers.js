import React from "react";
import MyTable from "../Table/Table";

const TopUsers = ({topUsers}) => {
    return (
        <div className='top_users_container'>
            <h2> Users Of The Month </h2>
            <MyTable user={topUsers[0]} markedValue='Orders'/>
            <br/>
            <MyTable user={topUsers[1]} markedValue='Payment'/>
        </div>
    );
}

export default TopUsers;
