import React, { Component } from "react";
import moment from "moment";
import "moment-duration-format";

class TasksShow extends Component {
  state = {
    task: ""
  };

  handleSubmit = e => {
    e.preventDefault();
    if (this.state.task) {
      const task = {
        id: ~~(Math.random() * 99999),
        totalTime: 0,
        task: this.state.task
      };
      this.props.createTask(task);
      this.setState({ task: "" });
    }
  };

  renderActiveTask() {
    const { activeTask } = this.props;
    if (activeTask) {
      return (
        <li className="collection-item avatar" key={activeTask.id}>
          <i className="material-icons circle green">grade</i>
          <p className="title">{activeTask.task}</p>
          <p
          >{`Total Time: ${moment
            .duration(activeTask.totalTime, "seconds")
            .format("hh:mm:ss", { trim: false })}`}</p>
        </li>
      );
    }
    return null;
  }

  renderTasks() {
    return this.props.tasks.map(task => {
      return (
        <li className="collection-item avatar" key={task.id}>
          <i
            className={
              this.props.activeTask ? "hide" : "material-icons circle grey"
            }
            style={styles.pointer}
            onClick={() => this.props.onTaskActivate(task)}
          >
            grade
          </i>
          <p className="title">{task.task}</p>
          <p
          >{`Total Time: ${moment
            .duration(task.totalTime, "seconds")
            .format("hh:mm:ss", { trim: false })}`}</p>
          <i
            style={styles.pointer}
            className="material-icons secondary-content"
            onClick={() => this.props.deleteTask(task)}
          >
            delete
          </i>
        </li>
      );
    });
  }

  render() {
    return (
      <div style={styles.container}>
        <ul className="collection with-header">
          <li className="collection-header">
            <form onSubmit={this.handleSubmit}>
              <input
                type="text"
                placeholder="Add a task"
                value={this.state.task}
                onChange={e => this.setState({ task: e.target.value })}
              />
            </form>
          </li>
          {this.renderActiveTask()}
          {this.renderTasks()}
        </ul>
      </div>
    );
  }
}

const styles = {
  container: {
    height: "100%",
    overflow: "scroll"
  },
  pointer: {
    cursor: "pointer"
  }
};

export default TasksShow;
