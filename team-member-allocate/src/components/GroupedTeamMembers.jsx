import React, { useState } from 'react';

const GroupedTeamMembers = ({employees, selectedTeam, setSelectedTeam}) => {
    const [groupeEmployee, setGroupEmployee] = useState(groupTeamMember);
    
    const groupTeamMember = () => {
        var teams = []

        var teamAMembers = employees.filter((emp) => emp.teamName === 'TeamA')
        var teamA = { team: 'TeamA', member: teamAMembers, collapsed: selectedTeam === 'TeamA' ? false : true }
        teams.push(teamA)

        var teamBMembers = employees.filter((emp) => emp.teamName === 'TeamB')
        var teamB = { team: 'TeamB', member: teamBMembers, collapsed: selectedTeam === 'TeamB' ? false : true }
        teams.push(teamB)

        var teamCMembers = employees.filter((emp) => emp.teamName === 'Teamc')
        var teamC = { team: 'TeamB', member: teamCMembers, collapsed: selectedTeam === 'TeamC' ? false : true }
        teams.push(teamC)

        var teamDMembers = employees.filter((emp) => emp.teamName === 'TeamD')
        var teamD = { team: 'TeamD', member: teamDMembers, collapsed: selectedTeam === 'TeamD' ? false : true }
        teams.push(teamD)
        
        return teams
    }


    const handleTeeamClick = (event) => {

    }


    return (
        <main className='container'> 
            <div className="row justify-content-center mt-3 mb-3">
                <div className="col-8">
                    {
                        groupeEmployee.map(
                            (item) => {
                                return (
                                    <div key={item.team} className='card mt-2' style={{ cursor: 'pointer' }}>
                                        <h4 className="card-header text-secandary bg-white" onClick={handleTeeamClick}>
                                            Team Name : {item.team}
                                        </h4>
                                        <div key={'collapse' + item.team} className={item.collapsed === true ? "collapsed" : ""}>
                                            <hr />
                                            {
                                                item.member.map(
                                                    member => {
                                                        return (
                                                            <div className='mt-2'>
                                                                <h5 className="card-title mt-2">
                                                                   Full Name : {member.fullname} 
                                                                </h5>
                                                                <p>Designation : {member.designation }</p>
                                                            </div>
                                                        )
                                                    }
                                                )
                                            }
                                        </div>
                                    </div>
                                )
                            }
                        )
                    }
                </div>
            </div>
        </main>
    );
};

export default GroupedTeamMembers;