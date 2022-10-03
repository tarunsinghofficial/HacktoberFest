import React from 'react'

function Contact() {
    return (
        <>
            <div className="container p-5" style={{backgroundColor: '#f4f4f4'}}>
                <div className="row">
                    <div className="col-lg-6 col-md-6 col-sm-12">
                        <h1>Contact Us</h1>
                        <div className="contact">
                            <div className="my-2">
                                <input type="name" className="form-control" id="exampleFormControlInput1" placeholder="Your Name" />
                            </div>
                            <div className="my-2">
                                <input type="email" className="form-control" id="exampleFormControlInput2" placeholder="Email" />
                            </div>
                            <div className="my-2">
                                <input type="tel" className="form-control" id="exampleFormControlInput3" placeholder="Contact No" />
                            </div>
                            <div className="my-2">
                                <textarea className="form-control" id="exampleFormControlTextarea1" rows="3"></textarea>
                            </div>
                            <button className="btn btn-outline-success">Submit</button>
                        </div>
                    </div>
                    <div className="col-lg-6 col-md-6 col-sm-12"></div>
                </div>
            </div>
        </>
    )
}

export default Contact
