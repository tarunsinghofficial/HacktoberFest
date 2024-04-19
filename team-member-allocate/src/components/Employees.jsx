  import React from "react";
import femalProfile from "../assets/images/femaleProfile.jpg";
import maleProfile from "../assets/images/maleProfile.jpg";

const Employees = ({handleEmployeCardClick, employees, selectedTeam, handleTeamSelectionChange}) => {

  return (
    <main className="container">
      <div className="row justify-content-center mt-3 mb-3">
        <div className="col-8">
          <select
            name="team"
            id="team"
            className="form-select form-select-lg"
            value={selectedTeam}
            onChange={handleTeamSelectionChange}
          >
            <option value="TeamA">Team A</option>
            <option value="TeamB">Team B</option>
            <option value="TeamC">Team C</option>
            <option value="TeamD">Team D</option>
          </select>
        </div>
      </div>
      <div className="row justify-content-center mt-3 mb-3">
        <div className="col-8">
          <div className="card-collection">
            {employees.map((emp) => (
              <div
                className={
                  emp.teamName === selectedTeam
                    ? "card m-2 standout"
                    : "card m-2"
                }
                style={{ cursor: "pointer" }}
                id={emp.id}
                key = {emp.id}
                onClick={handleEmployeCardClick}
              >
                <img
                  src={emp.gender === "male" ? maleProfile : femalProfile}
                  alt="maleProfile"
                  className="card-image-top"
                />
                <div className="card-body">
                  <h5 className="card-title">FullName{emp.fullName}</h5>
                  <p className="card-text">
                    <b>Designation</b>
                    {emp.designation}
                  </p>
                </div>
              </div>
            ))}
          </div>
        </div>
      </div>
    </main>
  );
};

export default Employees;
