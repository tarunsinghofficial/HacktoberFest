import moment from "moment";
import "moment-duration-format";

class Timer {
  constructor(config) {
    const {
      duration,
      unit,
      onDisplayChange,
      onTimerExpiration
    } = this.validateConfigObject(config);

    this.initialDuration = this.getInitialDuration(duration, unit);
    this.duration = this.initialDuration;
    this.delay = 100;
    this.display = this.getTimeDisplay();
    this.interval = null;
    this.startTime = null;
    this.onDisplayChange = onDisplayChange;
    this.onTimerExpiration = onTimerExpiration;
  }

  start(cb) {
    if (!this.interval) {
      this.startTime = moment();
      this.interval = setInterval(() => {
        this.duration -= this.delay;
        this.updateDisplay();
        this.listenForExpiration();
      }, this.delay);
      return cb ? cb() : null;
    }
  }

  stop(cb) {
    if (this.interval) {
      clearInterval(this.interval);
      this.interval = null;
      return cb ? cb() : null;
    }
  }

  reset() {
    console.log(moment() - this.startTime);
    this.stop();
    this.duration = this.initialDuration;
    this.updateDisplay(true);
  }

  updateDisplay(reset = false) {
    const newDisplay = this.getTimeDisplay();
    if (this.display !== newDisplay) {
      this.display = newDisplay;
      this.onDisplayChange(this.display, { reset });
    }
  }

  listenForExpiration() {
    if (this.duration <= 0) {
      this.reset();
      this.onTimerExpiration();
    }
  }

  getInitialDuration(duration, unit) {
    return moment.duration(duration, unit).asMilliseconds();
  }

  getTimeDisplay() {
    return moment.duration(this.duration).format("hh:mm:ss", { trim: false });
  }

  validateConfigObject(config) {
    const { unit, onDisplayChange, onTimerExpiration } = config;

    const duration = parseInt(config.duration);
    if (typeof duration !== "number") {
      throw new TypeError("Timer class requires duration = Number");
    }

    const validUnits = {
      seconds: true,
      minutes: true,
      hours: true
    };

    if (!validUnits[unit]) {
      throw new TypeError(
        "Timer class requires valid unit of time (seconds, minutes, or hours)"
      );
    }

    if (
      typeof onDisplayChange !== "function" ||
      typeof onTimerExpiration !== "function"
    ) {
      throw new TypeError(
        "Timer class requires 2 callback functions: onDisplayChange and onTimerExpiration"
      );
    }

    return { duration, unit, onDisplayChange, onTimerExpiration };
  }
}

export default Timer;
