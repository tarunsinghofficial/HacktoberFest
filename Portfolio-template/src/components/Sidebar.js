import React from "react";

import { Link } from "react-router-dom";
import LottieAnimation from "./Lottie";
import HomeIcon from "../images/home.svg";

import people from "../lotties/people.json";
import skill from "../lotties/skill.json";
import consult from "../lotties/consult.json";
const Sidebar = () => {
  const logo ='add '
  return (
    <div className="sidebar">
      <div className="sidebar__flex">
        <Link to="/">
          {/* add your logo here  */}
          <img className="sidebar_logo" src={logo} alt="logo" />
        </Link>
        <div className="sidebar_icon">
          {" "}
          <nav className="sidebar_icon_nav">
            <Link to="/home">
              <div className="sidebar-all-icons">
                <img
                  src={HomeIcon}
                  alt=""
                  className="sidebar__icons sidehome"
                />
              </div>
            </Link>
            <Link to="/about">
              <div className="sidebar-all-icons">
                <LottieAnimation
                  className="sidebar__icons"
                  lotti={people}
                  height={45}
                  width={40}
                />
              </div>
            </Link>
            <Link to="/skills">
              <div className="sidebar-all-icons">
                <LottieAnimation
                  className="sidebar__icons"
                  lotti={skill}
                  height={45}
                  width={40}
                />
              </div>
            </Link>
            <Link to="/contact">
              <div className="sidebar-all-icons">
                <LottieAnimation
                  className="sidebar__icons"
                  lotti={consult}
                  height={45}
                  width={40}
                />
              </div>
            </Link>
          </nav>
        </div>
      </div>
    </div>
  );
};

export default Sidebar;
