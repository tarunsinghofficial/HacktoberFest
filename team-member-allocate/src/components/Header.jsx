import React from "react";

const Header = ({ numberTeamSelected, selectedTeam }) => {
  return (
    <header className="container">
      <div className="row justify=content-center mt-3 mb-4">
        <div className="col-8">
          <h1 className="">Team Member Allocation</h1>
          <h3 className="">
            {selectedTeam} has {numberTeamSelected}Members
          </h3>
        </div>
      </div>
    </header>
  );
};

export default Header;
