import React, { Component } from "react";
import styles from "./DetailViewYourRoom.module.css";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
// import { faStar, faCheckCircle, faFan, faTv, faBed } from "@fortawesome/free-solid-svg-icons";
import {
  faStar,
  faCheckCircle,
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
  faCheese,
  faRestroom,
  faParking,
  faBed,
  faThermometerEmpty,
  faChair,
  faTv,
  faSoap,
} from "@fortawesome/free-solid-svg-icons";
import {
  hotelEntityDataRequest,
  hotelBillingDataRequest,
  hotelReviewDataRequest,
} from "../../../redux/authentication/actions";
import { connect } from "react-redux";
import DetailViewRoomCard from "./DetialViewRoomCard";
import DetailViewRoomSelected from "./DetailViewRoomSelected";

class DetailViewYourRomm extends Component {
  componentDidMount = () => {
    const {
      hotelEntityDataRequest,
      hotelBillingDataRequest,
      hotelReviewDataRequest,
    } = this.props;

    hotelBillingDataRequest({
      hotel_id: "10",
      room_id: "1",
      check_in: "01/08/2020",
      check_out: "02/08/2020",
      no_of_guests: "2",
      no_of_rooms: "2",
      membership: true,
    });
    // hotelReviewDataRequest(10)
  };

  render() {
    // let rooms,selected
    if (this.props.billingData) {
      const { billingData } = this.props;
      const { rooms, selected } = billingData;
      console.log(billingData);
      return (
        <>
          <div className="px-4" id={styles.heading}>
            Choose your room
          </div>

          <DetailViewRoomSelected data={rooms} selected={selected} />
          {rooms &&
            rooms.map((ele) =>
              ele.id !== selected.id ? (
                <DetailViewRoomCard data={ele} selected={selected} />
              ) : (
                false
              )
            )}
        </>
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
});

const mapDispatchToProps = (dispatch) => ({
  hotelEntityDataRequest: (payload) =>
    dispatch(hotelEntityDataRequest(payload)),
  hotelBillingDataRequest: (payload) =>
    dispatch(hotelBillingDataRequest(payload)),
  hotelReviewDataRequest: (payload) =>
    dispatch(hotelReviewDataRequest(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(DetailViewYourRomm);
