import React from 'react'

import { MdProductionQuantityLimits, MdContactPhone } from "react-icons/md";
import { FaIndustry } from "react-icons/fa";
import { GrCertificate, GrLinkNext, GrLocation } from "react-icons/gr";

import './Home.css'

import BgImg from '../../images/Hero-bg1.jpeg'

import ImgCarousel from '../carousels/ImgCarousel.js'
import Item from './Item.js';
// import Contact from '../contact/Contact.js';

function Home() {

    const parallex = {
        backgroundImage: `url(${BgImg})`,
        backgroundAttachment: "fixed",
        backgroundPosition: "center",
        backgroundRepeat: "no-repeat",
        backgroundSize: "cover",
    };

    return (
        <>
            <section className="py-5 bgImg" style={parallex}>
                <div className="container">
                    <div className="px-4 text-center">
                        <h1 className="display-5 fw-bold my-3">APOORBA INDUSTRIES</h1>
                        <div className="col-lg-6 mx-auto">
                            <p className="lead mb-4">Manufacturer Plastic Items <br />Meeting the market requirements within the widest scope <br />High Quality is the Goal We Achieved </p>
                            <div className="d-grid gap-2 d-sm-flex justify-content-sm-center">
                                <button type="button" className="btn btn-outline-primary btn-lg px-4 gap-3">Primary button</button>
                                <button type="button" className="btn btn-outline-secondary btn-lg px-4">Secondary</button>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
            <section className='py-5' >
                <div className="container">
                    <div className="row">
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <h1 className='my-3'>About Our Company</h1>
                            <h4>company tagline</h4>
                        </div>
                        <div className="col-lg-1 col-md-1 col-sm-0">
                            <div className="d-flex" style={{ height: "200px" }}>
                                <div className="vr"></div>
                            </div>
                        </div>
                        <div className="col-lg-7 col-md-7 col-sm-12">
                            <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Iste inventore qui illo, necessitatibus atque at rem cupiditate saepe pariatur cum ea odit totam similique voluptatibus nam quam repellat praesentium ipsum. Lorem ipsum dolor, sit amet consectetur adipisiam similique voluptatibus nam quam repellat praesentium ipsum. Lorem ipsum dolor, sit amet consectetur adipisicing elit. Similique ea facilis placeat nostrum fuga magni ex repellat, mollitia quae laudantium ipsum porro nisi consequatur illo delectus nihil iure quibusdam optio.</p>

                            <button className="btn btn-outline-success">Read More </button>
                        </div>
                    </div>
                </div>
            </section>

            <section className="py-5 homeSec3">
                <div className="container">
                    <div className="row">
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <div className='my-3'>
                                <h1>What Make Us Different ?</h1>
                            </div>

                            <div className='my-5'>
                                <h5>The company provides the best services by following up customer requests and implementing new suggestions</h5>
                            </div>

                            <button className="btn btn-outline-success">Learn More </button>
                        </div>
                        <div className="col-lg-8 col-md-8 col-sm-12">
                            <ImgCarousel />
                            <div className="container mt-5">
                                <div className="row">
                                    <div className="col-lg-4 col-md-4 col-sm-6">
                                        <MdProductionQuantityLimits fontSize='4rem' className='m-2' />
                                        <h4>HIGH QUALITY PRODUCTS</h4>
                                        <p>Produces high quality plastics according to the standards.</p>
                                    </div>
                                    <div className="col-lg-4 col-md-4 col-sm-6">
                                        <FaIndustry fontSize='4rem' className='m-2' />
                                        <h4>FUTURE OUTLOOK</h4>
                                        <p>We continuously develop production and open new markets & factories.</p>
                                    </div>
                                    <div className="col-lg-4 col-md-4 col-sm-6">
                                        <GrCertificate fontSize='4rem' className='m-2' />
                                        <h4>VARIOUS CERTIFICATIONS</h4>
                                        <p>High Quality is the aim we achieved and always seek to maintain.</p>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </section>

            <section className="py-5">
                <div className="container">
                    <div className="row">
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <Item />
                        </div>
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <Item />
                        </div>
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <Item />
                        </div>
                    </div>
                </div>
            </section>

            <section className="py-5" style={{ backgroundColor: '#1fd581', color: 'whitesmoke' }}>
                <div className="container">
                    <div className="row">
                        <div className="col-lg-8 col-md-8 col-sm-12">
                            <h2>We continuously develop production and
                                open new markets and factories.</h2>
                        </div>
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <div className="btn1">
                                <div><h4>See Current Deals <GrLinkNext /> </h4></div>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
            <section className='py-5'>
                <div className="container">
                    <div className="row">
                        <div className="col-lg-6 col-md-6 col-sm-12">
                            <h1>Office Contacts</h1>
                            <p>The company provides the best services by following up customer requests and implementing new suggestions</p>
                            <div className="address d-flex my-5">
                                <GrLocation fontSize='2rem' className='m-2' />
                                <h5>Andei Sahi, <br />Bhairpur, Salipur, Cuttack <br /> Pin: 754200</h5>
                            </div>
                            <div className="d-flex">
                                <MdContactPhone fontSize='2rem' className='m-2' />
                                <div>
                                    <h5>+91 9971103090</h5>
                                    <h5>kmr_ashwini@yahoo.co.in</h5>
                                </div>
                            </div>
                        </div>
                        <div className="col-lg-6 col-md-6 col-sm-12"></div>
                    </div>
                </div>
            </section>
        </>
    )
}

export default Home
