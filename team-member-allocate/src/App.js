  //import logo from './logo.svg';
import "./App.css";
import GroupedTeamMembers from "./components/GroupedTeamMembers";
import Footer from "./components/Footer";
import Header from "./components/Header";
import "bootstrap/dist/css/bootstrap.min.css";
import Employees from "./components/Employees";
import { useEffect, useState } from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Nav from "./components/Nav";
import NotFound from "./NotFound";

function App() {
  const [employees, setEmployees] = useState(
    JSON.parse(localStorage.getItem("employeeList")) || [
      {
        id: 1,
        fullName: "Bob Jones",
        designation: "JavaScript Developer",
        gender: "male",
        teamName: "TeamA",
      },
      {
        id: 2,
        fullName: "Jill Bailey",
        designation: "Node Developer",
        gender: "female",
        teamName: "TeamA",
      },
      {
        id: 3,
        fullName: "Gail Shepherd",
        designation: "Java Developer",
        gender: "female",
        teamName: "TeamA",
      },
      {
        id: 4,
        fullName: "Sam Reynolds",
        designation: "React Developer",
        gender: "male",
        teamName: "TeamB",
      },
      {
        id: 5,
        fullName: "David Henry",
        designation: "DotNet Developer",
        gender: "male",
        teamName: "TeamB",
      },
      {
        id: 6,
        fullName: "Sarah Blake",
        designation: "SQL Server DBA",
        gender: "female",
        teamName: "TeamB",
      },
      {
        id: 7,
        fullName: "James Bennet",
        designation: "Angular Developer",
        gender: "male",
        teamName: "TeamC",
      },
      {
        id: 8,
        fullName: "Jessica Faye",
        designation: "API Developer",
        gender: "female",
        teamName: "TeamC",
      },
      {
        id: 9,
        fullName: "Lita Stone",
        designation: "C++ Developer",
        gender: "female",
        teamName: "TeamC",
      },
      {
        id: 10,
        fullName: "Daniel Young",
        designation: "Python Developer",
        gender: "male",
        teamName: "TeamD",
      },
      {
        id: 11,
        fullName: "Adrian Jacobs",
        designation: "Vue Developer",
        gender: "male",
        teamName: "TeamD",
      },
      {
        id: 12,
        fullName: "Devin Monroe",
        designation: "Graphic Designer",
        gender: "male",
        teamName: "TeamD",
      },
    ]
  );

  const [selectedTeam, setSelectedTeam] = useState(
    JSON.parse(localStorage.getItem("selectedTeam")) || "TeamB"
  );
  const handleTeamSelectionChange = (event) => {
    setSelectedTeam(event.target.value);
  };
  const handleEmployeCardClick = (e) => {
    const transfomedEmployees = employees.map((empl) =>
      empl.id === parseInt(e.currentTarget.id)
        ? empl.teamName === selectedTeam
          ? { ...empl, teamName: "" }
          : { ...empl, teamName: selectedTeam }
        : empl
    );
    setEmployees(transfomedEmployees);
  };

  useEffect(() => {
    localStorage.setItem("employeeList", JSON.stringify(employees));
  }, [employees]);

  useEffect(() => {
    localStorage.setItem("selectedTeam", JSON.stringify(selectedTeam));
  }, [selectedTeam]);

  return (
    <div className="App">
      <Router>
      < Nav />   
        <Header
          numberTeamSelected={
            employees.filter((emp) => emp.teamName === selectedTeam).length
          }
          selectedTeam={selectedTeam}
        />
        
        <Routes>
          <Route
            path="/"
            element={
              <Employees
                employees={employees}
                selectedTeam={selectedTeam}
                handleTeamSelectionChange={handleTeamSelectionChange}
                handleEmployeCardClick={handleEmployeCardClick}
              />
            }
          ></Route>
          <Route path="/GroupedTeamMembers" element={< GroupedTeamMembers
            employees={employees}
            selectedTeam={selectedTeam}
            setSelectedTeam = {setSelectedTeam}
          />}></Route>
          <Route path="*" element={<NotFound />}></Route>
        </Routes>
        <Footer />
      </Router>
    </div>
  );
}

export default App;
