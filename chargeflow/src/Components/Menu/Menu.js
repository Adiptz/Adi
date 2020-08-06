import React from "react";
import {MenuList, MenuItem} from '@material-ui/core';

const Menu = () => {
    return (
        <MenuList id='menu'>
            <h1>Get On Board</h1>
            <MenuItem> Dashboard </MenuItem>
            <MenuItem> Payments </MenuItem>
            <MenuItem> Settings </MenuItem>
            <MenuItem> Users </MenuItem>

            <div className='service' style={{position: 'fixed', bottom: '30px'}}>
                <hr/>
                <MenuItem dense={true}> Contact Us </MenuItem>
                <MenuItem dense={true}> Manage </MenuItem>
            </div>
        </MenuList>
    );
}

export default Menu;