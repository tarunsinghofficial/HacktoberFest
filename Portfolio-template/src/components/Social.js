import React from "react";

const Social = ({ link, icon, socialname }) => {
  return (
    <>
      <a className="social_link" href={link}>
        <img className="social_icon" src={icon} alt={socialname} />
      </a>
    </>
  );
};

export default Social;
