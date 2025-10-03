import React, { Component } from "react";
import styles from "./PriceCard.module.css";
import { Link } from "react-router-dom";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import DateRangePicker from "react-bootstrap-daterangepicker";
import "bootstrap/dist/css/bootstrap.css";
import "bootstrap-daterangepicker/daterangepicker.css";

import {
  faStar,
  faDoorClosed,
  faPen,
  faTags,
  faFan,
  faToilet,
  faPersonBooth,
  faMusic,
  faHandHoldingWater,
  faMoneyBillWave,
  faBreadSlice,
  faWifi,
  faFire,
  faHotTub,
  faBed,
  faCheese,
  faRestroom,
  faParking,
  faThermometerEmpty,
  faChair,
  faTv,
  faSoap,
} from "@fortawesome/free-solid-svg-icons";
// import DateRangePicker from "react-bootstrap-daterangepicker";
// import "bootstrap/dist/css/bootstrap.css";
// import "bootstrap-daterangepicker/daterangepicker.css";
import { hotelEntityDataRequest, hotelBillingDataRequest, hotelReviewDataRequest } from "../../../redux/authentication/actions";
import { connect } from "react-redux";

class PriceCard extends Component {
  constructor(props) {
    super(props);
    this.state = {
      inputStart: "01/08/2020",
      inputFinish: "02/08/2020",
      checked: true,
    };
  }

  handleEvent = (event, picker) => {
    this.setState({
      inputStart: picker.startDate.format("DD/MM/YYYY"),
      inputFinish: picker.endDate.format("DD/MM/YYYY"),
    });
    const { rooms, selected } = this.props.billingData;
    const { offer, id, no_of_guests, no_of_rooms } = selected;
    const { inputStart, inputFinish } = this.state;
    const { hotelId, hotelBillingDataRequest } = this.props;
    hotelBillingDataRequest({
      hotel_id: hotelId,
      room_id: id,
      check_in: inputStart,
      check_out: inputFinish,
      no_of_guests,
      no_of_rooms,
      membership: offer.membership,
    });
    // console.log(picker.startDate, start, end, label);
  };

  handleChange = () => {
    const { rooms, selected } = this.props.billingData;
    const { offer, id, no_of_guests, no_of_rooms } = selected;
    const { inputStart, inputFinish } = this.state;
    const { hotelId, hotelBillingDataRequest } = this.props;
    hotelBillingDataRequest({
      hotel_id: hotelId,
      room_id: id,
      check_in: inputStart,
      check_out: inputFinish,
      no_of_guests,
      no_of_rooms,
      membership: !offer.membership,
    });
  };
  render() {
    console.log(this.state);
    if (this.props.billingData) {
      const { rooms, selected } = this.props.billingData;
      const { actual_price, check_in, check_out, discount, discount_price, id, no_of_guests, no_of_rooms, offer, type, size } = selected;
      const { hotelId } = this.props;
      console.log(hotelId, "id");
      const { handleChange } = this;
      return (
        <div className="col-5 mt-4 " id={styles.cardContainer}>
          <div className="row sticky-top">
            <div class="card w-100 ">
              <div className="d-flex justify-content-around" id={styles.header}>
                <div className="m-0">
                  <span id={styles.off}>Login now to get extra 10% Off</span>
                </div>
                <div id={styles.login}>
                  <span id={styles.loginButton}>LOGIN</span>
                </div>
              </div>
              <div class="card-body">
                <div>
                  <div className="d-flex flex-wrap align-items-center">
                    <span id={styles.finalPrice}>₹{discount_price}</span>
                    <span id={styles.discount}>₹{actual_price}</span>
                    <span id={styles.perOff}>{discount}% off</span>
                  </div>
                  <div id={styles.perNight}>inclusive of all taxes</div>
                </div>
                <div className="d-flex justify-content-around" id={styles.SecduleContainer}>
                  <DateRangePicker autoUpdateInput={false} startDate={this.state.inputStart} endDate={this.state.inputFinish} locale={{ format: "DD/MM/YYYY" }} onApply={this.handleEvent} autoApply={true}>
                    <div>
                      <span>{check_in}</span>
                      <span>-</span>
                      <span>{check_out}</span>
                    </div>
                  </DateRangePicker>
                  <div id={styles.divide}></div>
                  <div>
                    <span>
                      {no_of_guests} Rooms, {no_of_rooms} Guests
                    </span>
                  </div>
                </div>
                <div className="d-flex justify-content-between" id={styles.SecduleContainer}>
                  <div>
                    <span>
                      <FontAwesomeIcon icon={faDoorClosed} color="#f0f0f0" size="sm" />
                    </span>
                    <span className="ml-2">{type}</span>
                  </div>
                  <div>
                    <span>
                      <FontAwesomeIcon icon={faPen} color="red" size="sm" />
                    </span>
                  </div>
                </div>
                <div id={styles.tagContainer}>
                  <div>
                    <div>
                      <span>
                        <FontAwesomeIcon icon={faTags} color="#f5a623" size="sm" />
                      </span>
                      <span id={styles.coupon}>Apply offers</span>
                    </div>
                  </div>
                  <div onClick={() => handleChange()}>
                    <input type="checkbox" checked={offer.membership} />
                    <span id={styles.moreOffer}>membership</span>
                  </div>
                </div>
                <div className="d-flex justify-content-between mt-4">
                  <div>
                    <div id={styles.totalPrice}>Savings</div>
                  </div>
                  <div>
                    <span id={styles.actualPrice}>₹{offer && offer.savings}</span>
                  </div>
                </div>
                <div className="d-flex justify-content-between mt-4">
                  <div>
                    <div id={styles.totalPrice}>Total price</div>
                    <div id={styles.tax}>(incl. of all taxes)</div>
                  </div>
                  <div>
                    <span id={styles.actualPrice}>₹{discount_price}</span>
                  </div>
                </div>
                <div className="mt-5">
                  <Link to={`/entity/${hotelId}/payment`}>
                    <button>Continue to Book </button>
                  </Link>
                </div>
                <div className="mt-2" id={styles.policy}>
                  <div>10 people booked this hotel today</div>
                  <div className="mt-3">Cancellation Policy</div>
                  <div>Follow safety measures advised at the hotel</div>
                  <div>
                    <span className="text-secondary mt-3">By proceeding, you agree to our</span> Guest Policies.
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      );
    }
    return "loading...";
  }
}

const mapStateToProps = (state) => ({
  token: state.auth.token,
  user: state.auth.user,
  entityData: state.auth.entityData,
  review: state.auth.review,
  billingData: state.auth.billingData,
  hotelId: state.auth.hotelId,
});

const mapDispatchToProps = (dispatch) => ({
  hotelEntityDataRequest: (payload) => dispatch(hotelEntityDataRequest(payload)),
  hotelBillingDataRequest: (payload) => dispatch(hotelBillingDataRequest(payload)),
  hotelReviewDataRequest: (payload) => dispatch(hotelReviewDataRequest(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(PriceCard);
