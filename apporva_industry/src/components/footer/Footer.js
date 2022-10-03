import React from 'react'

import { AiFillFacebook, AiFillTwitterSquare, AiFillInstagram } from "react-icons/ai";

function Footer() {
    return (
        <>
            <footer className="d-flex flex-wrap justify-content-between align-items-center py-3 my-4 border-top">
                <div className="col-md-4 d-flex align-items-center">
                    <a href="/" className="mb-3 me-2 mb-md-0 text-muted text-decoration-none lh-1">
                        <svg className="bi" width="30" height="24"></svg>
                    </a>
                    <span className="mb-3 mb-md-0 text-muted">© 2022 Company, Inc</span>
                </div>

                <ul className="nav col-md-4 justify-content-end list-unstyled d-flex">
                    <li className="ms-3"><a className="text-muted" href="/"><AiFillFacebook fontSize='2.5rem' /></a></li>
                    <li className="ms-3"><a className="text-muted" href="/"><AiFillTwitterSquare fontSize='2.5rem' /></a></li>
                    <li className="ms-3"><a className="text-muted" href="/"><AiFillInstagram fontSize='2.5rem' /></a></li>
                </ul>
            </footer>
        </>
    )
}

export default Footer
