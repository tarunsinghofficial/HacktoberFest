import React from 'react';
import {NavLink} from 'react-router-dom'
const Nav = () => {
    return (
        <div className='navbar navbar-expand-light bg-light'>
            <ul className="navbar-nav me-auto mb-2 mbb-lg-0">
                <li className='nav-item'>
                    <NavLink to='/' className='nav-link'>Home</NavLink>
                </li>
                <li className='nav-item'>
                <NavLink to='/GroupedTeamMembers' className='nav-link'>Grouped Team Members</NavLink>
                </li>
            </ul>
        </div>
    );
};

export default Nav;