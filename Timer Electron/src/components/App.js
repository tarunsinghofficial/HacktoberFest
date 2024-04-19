import React, { Component } from "react";
import { Route, Switch } from "react-router-dom";

import Header from "./Header";
import TasksIndex from "./TasksIndex";
import TasksShow from "./TasksShow";
import Timer from "../utils/Timer";
import Settings from "./Settings";

const APP_DATA = JSON.parse(localStorage.getItem("__INITIAL_STATE__"));

const INITIAL_STATE = {
  tasks: [
    { id: 1, task: "Build App1", totalTime: 10 },
    { id: 2, task: "Build App2", totalTime: 60 },
    { id: 3, task: "Build App3", totalTime: 1000 },
    { id: 4, task: "Build App4", totalTime: 10000 },
    { id: 5, task: "Build App5", totalTime: 100000 }
  ],
  activeTask: null,
  timer: {
    active: false,
    time: 10,
    unit: "seconds",
    display: ""
  }
};

class App extends Component {
  static defaultProps = {
    updateTrayText: () => {},
    onTimerExpire: () => {}
  };

  constructor(props) {
    super(props);
    this.state = APP_DATA || INITIAL_STATE;

    this.onAppClose();
  }

  // --------------------------------------------------
  // -------- electron event handlers -----------------
  // --------------------------------------------------

  onAppClose = () => {

  };

  updateTrayText = title => {

  };

  timerHasExpired = () => {

  };

  // -------- end of electron event handerls ----------

  componentDidMount() {
    this.initializeTimer();
  }

  componentDidUpdate() {
    localStorage.setItem("__INITIAL_STATE__", JSON.stringify(this.state));
  }

  initializeTimer(timerSettings = {}) {
    const { time, unit } = timerSettings;
    const timerConfig = {
      duration: time || this.state.timer.time,
      unit: unit || this.state.timer.unit,
      onDisplayChange: this.handleTimerUpdate,
      onTimerExpiration: this.handleTimerExpiration
    };
    this.timer = new Timer(timerConfig);
  }

  handleTimerUpdate = (newDisplay, reset) => {
    this.setState(prevState => {
      const { timer, activeTask } = prevState;
      const { active } = timer;
      const updateTaskTime = active && !reset.reset;
      return {
        timer: { ...timer, display: newDisplay },

        activeTask: {
          ...activeTask,
          totalTime: updateTaskTime
            ? activeTask.totalTime + 1
            : activeTask.totalTime
        }
      };
    });

    // handler for electron tray title
    this.updateTrayText(newDisplay);
  };

  handleTimerExpiration = () => {
    this.setState({
      timer: { ...this.state.timer, active: false }
    });
    this.timerHasExpired(); // handler for electron Notifications
  };

  createTask = task => {
    this.setState({
      tasks: [task, ...this.state.tasks]
    });
  };

  deleteTask = task => {
    this.setState({
      tasks: this.state.tasks.filter(item => item.id !== task.id)
    });
  };

  handleSettingsUpdate = newSettings => {
    this.initializeTimer(newSettings);
    this.setState({
      timer: {
        ...this.state.timer,
        ...newSettings,
        display: this.timer.display
      }
    });
  };

  handleDataReset = () => {
    this.setState({ ...INITIAL_STATE });
  };

  handleActivation = task => {
    this.initializeTimer();
    this.setState({
      tasks: this.state.tasks.filter(item => item.id !== task.id),
      activeTask: task,
      timer: {
        ...this.state.timer,
        display: this.timer.display
      }
    });
  };

  handleDeactivation = activeTask => {
    this.setState({
      tasks: [activeTask, ...this.state.tasks],
      activeTask: null
    });
  };

  handleTimerStart = () => {
    this.timer.start(() => {
      // sending a callback so there is no delay in rendering start/stop buttons
      this.setState({
        timer: { ...this.state.timer, active: true }
      });
    });
  };

  handleTimerStop = () => {
    this.timer.stop(() => {
      this.setState({
        timer: { ...this.state.timer, active: false }
      });
    });
  };

  render() {
    const { tasks, activeTask, timer } = this.state;
    return (
      <div>
        <Header />
        <div className="container" style={styles.container}>
          <Switch>
            <Route
              exact
              path="/"
              render={() => (
                <TasksIndex
                  activeTask={activeTask}
                  onTaskDeactivate={this.handleDeactivation}
                  onTimerStart={this.handleTimerStart}
                  onTimerStop={this.handleTimerStop}
                  timer={timer}
                />
              )}
            />
            <Route
              path="/tasks"
              render={() => (
                <TasksShow
                  tasks={tasks}
                  activeTask={activeTask}
                  createTask={this.createTask}
                  deleteTask={this.deleteTask}
                  onTaskActivate={this.handleActivation}
                />
              )}
            />
            <Route
              path="/settings"
              render={() => (
                <Settings
                  timer={timer}
                  handleSubmit={this.handleSettingsUpdate}
                  handleDataReset={this.handleDataReset}
                />
              )}
            />
          </Switch>
        </div>
      </div>
    );
  }
}

const styles = {
  container: {
    height: "88vh"
  }
};

export default App;
