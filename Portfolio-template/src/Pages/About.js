import React from "react";
import { Link } from "react-router-dom";
const About = () => {
  return (
    <div className="about">
      <div className="about_top">
        <p>{`<html>`}</p>
        <p>{`<body>`}</p>
      </div>
      <div className="about_mid">
        <div className="about_mid_left">
          <p> {`<h1>`}</p>
          <h1>About us</h1>
          <p> {`</h1>`}</p>
          <h4>
            We are a team of professionals connected with the web development
            industry and information technology for many years.
          </h4>
          <h4>
            Well-organized persons,problem solvers,independent employees with
            high attention to detail and have calibre in UI/UX designing.
          </h4>
          <h4>
            Intrested in the entire frontend spectrum and working on ambitious
            projects with positive people.
          </h4>
          <div className="about_mid_buttonContainer">
 
          </div>
        </div>
        {/* <div className="about_mid_right">
          <div className="about_mid_right_info">
              <div className="about_mid_right_info_card_container">
            <img className="about_mid_right_profilePic" src={Anish} alt="" />
            <p>
jhadkljsdl;fl;dkg;lfkg;kh;tkhlojijfbkfjhkhghrlgirgjlerjtoieufojreifherkghleighorei
            </p>
            </div>
          </div>
        </div> */}
      </div>
      <div className="about_bottom">
        <p>{`</body>`}</p>
        <p>{`</html>`}</p>
      </div>
    </div>
  );
};

export default About;
