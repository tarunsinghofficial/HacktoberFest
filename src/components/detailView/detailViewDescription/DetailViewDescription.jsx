import React, { Component } from "react";
import styles from "./DetailViewDescription.module.css";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { loadData } from "../../../redux/authentication/localStorage";
// import { faStar } from "@fortawesome/free-solid-svg-icons";
import {
  faStar,
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
import { hotelEntityDataRequest, hotelBillingDataRequest, hotelReviewDataRequest } from "../../../redux/authentication/actions";
import { connect } from "react-redux";

class DetailViewDescription extends Component {
  componentDidMount = () => {
    const { hotelEntityDataRequest, hotelBillingDataRequest, hotelReviewDataRequest } = this.props;

    //  hotelBillingDataRequest({
    //   hotel_id:"10",
    //   room_id:"1",
    //   check_in:"01/01/2020",
    //   check_out:"01/01/2020",
    //   no_of_guests:"2",
    //   no_of_rooms:"2",
    //   membership: true
    // })
    console.log(this.props.id, "data");
    hotelEntityDataRequest(this.props.id);
  };
  // shouldComponentUpdate=()=>{
  //   // const {hotelBillingDataRequest,entityData} = this.props
  //   const {entityData,billingData,review} = this.props
  //   console.log(entityData,billingData,review)
  //   // setTimeout(()=>{

  //   // },1000)
  // }
  render() {
    const { entityData, billingData, review } = this.props;
    console.log(entityData, billingData, review);
    let address = loadData("address");
    return (
      <>
        <div className="col-12 px-3">
          <div className="d-flex justify-content-around " id={styles.headingContainer}>
            <h1 id={styles.heading}>{entityData ? entityData.name : "loading.."}</h1>
            <div className="mr-5 ">
              <div className="d-flex bg-success justify-content-around" id={styles.ratingIcons}>
                <div>{entityData ? Number(entityData.rating).toFixed(1) : 0}</div>
                <span>
                  <FontAwesomeIcon icon={faStar} color="#fff" size="sm" />
                </span>
              </div>
              <div id={styles.rating}>
                <span>{entityData ? entityData.no_of_ratings : 0} Ratings</span>
              </div>
            </div>
          </div>
          <div>
            <span className="m-4 pl-2" id={styles.subHeading}>
              {address}
            </span>
          </div>
          <div className="d-flex justify-content-start ml-4" id={styles.badgeBox}>
            <div>
              <span id={styles.badgeLeft}>TOWNHOUSE</span>
            </div>
            <div>
              <span id={styles.operate}>Operated by EYO</span>
            </div>
          </div>
        </div>
        <div className="col-12  px-3 mt-5">
          <div className="px-4">
            <div>
              <span id={styles.Des}>Description</span>
            </div>
            <div>
              <span id={styles.DesDetail}>
                {/* {entityData.description} */}
                The COVID19 pandemic has made us all understand the importance of sanitization and not take it for granted. Rest assured, we have reached out to our partners to uphold the highest standards of sanitation and safety.
              </span>
            </div>
            <div id={styles.location}>
              <strong>Location</strong>
              <div>
                <span id={styles.hotelDetail}>Hotel Mannat International is well-decorated property located close to the famous Tiljala road in Kolkata.</span>
              </div>
            </div>
          </div>
        </div>
      </>
    );
  }
}

const mapStateToProps = (state) => ({
  token: state.auth.token,
  user: state.auth.user,
  entityData: state.auth.entityData,
  review: state.auth.review,
});

const mapDispatchToProps = (dispatch) => ({
  hotelEntityDataRequest: (payload) => dispatch(hotelEntityDataRequest(payload)),
  hotelBillingDataRequest: (payload) => dispatch(hotelBillingDataRequest(payload)),
  hotelReviewDataRequest: (payload) => dispatch(hotelReviewDataRequest(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(DetailViewDescription);
