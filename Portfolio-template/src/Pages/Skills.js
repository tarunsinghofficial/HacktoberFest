import React from "react";

const Skills = () => {
  return (
    <div className="skill">
      <div className="skill_top">
        <p>{`<html>`}</p>
        <p>{`<body>`}</p>
      </div>
      <div className="skill_mid">
        <div className="skill_content">
          <p> {`<h1>`}</p>
          <h1>Skills & Experience</h1>
          <p> {`</h1>`}</p>
          <h4>
            The main area of our expertise is front end development and UI/UX
            designs.
          </h4>
          <h4>
            HTML, CSS, JS, React, Gatsby, and building small and medium web
            applications with NextJs, Custom plugins, features, animations, and
            coding interactive layouts.
          </h4>
          <h4>I  also have full-stack developer experience.</h4>
        </div>

      </div>
      <div className="skill_bottom">
        <p>{`</body>`}</p>
        <p>{`</html>`}</p>
      </div>
    </div>
  );
};

export default Skills;
