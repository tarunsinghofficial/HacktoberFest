import React, { Component } from "react";

class Settings extends Component {
  constructor(props) {
    super(props);

    this.state = {
      time: props.timer.time,
      unit: props.timer.unit
    };
  }

  onSubmit = e => {
    e.preventDefault();
    this.props.handleSubmit(this.state);
  };

  buttonStyle = () => {
    const { time, unit } = this.state;
    const propsTime = this.props.timer.time;
    const propsUnit = this.props.timer.unit;

    if (time == propsTime && unit == propsUnit) {
      // double equals to avoid type check
      return "btn disabled";
    }

    if (this.props.timer.active) {
      return "btn disabled";
    }

    return "btn";
  };

  render() {
    return (
      <div style={styles.container}>
        <ul className="collection with-header">
          <li className="collection-header">
            Settings
          </li>
          <form onSubmit={this.onSubmit}>
            <li className="collection-item">
              <p>Initial Duration</p>
              <input
                type="number"
                min="1"
                value={this.state.time}
                onChange={e => this.setState({ time: e.target.value })}
              />
            </li>
            <li className="collection-item">
              <p>Units</p>
              <select
                className="browser-default"
                value={this.state.unit}
                onChange={e => this.setState({ unit: e.target.value })}
              >
                <option value="seconds">Seconds</option>
                <option value="minutes">Minutes</option>
                <option value="hours">Hours</option>
              </select>
            </li>
            <li className="collection-item right">
              <button type="submit" className={this.buttonStyle()}>Save</button>
            </li>
          </form>
        </ul>
        <button className="btn red" onClick={this.props.handleDataReset}>
          Reset Data
        </button>
      </div>
    );
  }
}

const styles = {
  container: {
    display: "flex",
    flexDirection: "column"
  },
  pointer: {
    cursor: "pointer"
  }
};

export default Settings;
