import React from "react";
import {Link} from "react-router-dom";

const NavBar = () => {
    return (
        <nav>
         <img className='logo-OECD' src={require('../../images/logo-OECD.svg.png')}/>
            <ul className='nav-links'>
                <Link to={'/'}>
                    <li>Who We Are</li>
                </Link>

                <Link to={'/custom'}>
                    <li>Custom Board</li>
                </Link>

            </ul>
        </nav>
    );
}

export default NavBar;