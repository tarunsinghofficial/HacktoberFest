import React from 'react'

import { AiFillFacebook, AiFillTwitterSquare, AiFillInstagram, AiFillYoutube } from "react-icons/ai";

function Navbar() {
    return (
        <>
            <div className="alert py-1" style={{ backgroundColor: 'black', color: 'white', borderRadius: '0px' }}>
                <div className="d-flex justify-content-between">
                    <div className='socials' >
                        <AiFillFacebook className='mx-1' fontSize='1.3rem' />
                        <AiFillTwitterSquare className='mx-1' fontSize='1.3rem' />
                        <AiFillInstagram className='mx-1' fontSize='1.3rem' />
                        <AiFillYoutube className='mx-1' fontSize='1.3rem' />
                    </div>
                    <div className='contact d-flex' >
                        <div className='mx-3' >Office: 123-456-789</div>
                        <div className='mx-3' >Factory: 123-456-789</div>

                    </div>
                </div>
            </div>
            <nav className="navbar navbar-expand-lg bg-light">
                <div className="container-fluid">
                    <a className="navbar-brand" href='/'>Navbar</a>
                    <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                        <span className="navbar-toggler-icon"></span>
                    </button>
                    <div className="collapse navbar-collapse" id="navbarSupportedContent">
                        <ul className="navbar-nav mx-auto mb-lg-0">
                            <li className="nav-item mx-2">
                                <a className="nav-link active" aria-current="page" href='/'>Home</a>
                            </li>
                            <li className="nav-item mx-2">
                                <a className="nav-link" href='/'>Company Profile</a>
                            </li>
                            <li className="nav-item mx-2">
                                <a className="nav-link" href='/'>Our Products</a>
                            </li>
                            <li className="nav-item mx-2">
                                <a className="nav-link" href='/'>Contact Us</a>
                            </li>
                        </ul>
                    </div>
                </div>
            </nav>
        </>
    )
}

export default Navbar
