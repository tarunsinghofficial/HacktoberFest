import React from "react";
import { Link } from "react-router-dom";
import logo from "../images/logo.png";
const Home = () => {
  return (
    <div className="home">
      <div className="home_top">
        <p>{`<html>`}</p>
        <p>{`<body>`}</p>
      </div>
      <div className="home_mid">
        <p>{`<h1/>`}</p>
        <h1>Hi,</h1>
        <h1>
          You can add
          <span>
            {/* you can add you logo here */}
            {/* <img className="home_mid_logo" src='' alt="logo" /> */}
          </span>
           your Name,
        </h1>
        <h1>I am  web developers.</h1>
        <h4>Full-stack developers | UI/UX designer</h4>
        <p>{`</h1>`}</p>
        <div className="home_mid_button">
          <Link className="home_mid_contactButton" to="/contact">
            Contact us!
          </Link>
        </div>
      </div>
      <div className="home_bottom">
        <p>{`</body>`}</p>
        <p>{`</html>`}</p>
      </div>
    </div>
  );
};

export default Home;
