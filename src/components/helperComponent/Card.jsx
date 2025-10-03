import React, { Component } from "react";
import nonMapViewCss from "./card.module.css";
import MapViewCss from "./CardSmall.module.css";
import { Link } from "react-router-dom";
import { loadData } from "../../redux/authentication/localStorage";

import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
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
  faBed,
  faCheese,
  faRestroom,
  faParking,
  faThermometerEmpty,
  faChair,
  faTv,
  faSoap,
  faBold,
  faBone,
  faDotCircle,
  faTags,
  faPen,
} from "@fortawesome/free-solid-svg-icons";
import { hotelListingDataRequest, hotelEntityDataRequest, hotelBillingDataRequest, hotelReviewDataRequest } from "../../redux/authentication/actions";
import { connect } from "react-redux";
import { Redirect } from "react-router-dom";
class Card extends Component {
  changeToEntityPage = (id) => {
    console.log("calling entity page", id);
    const { hotelEntityDataRequest, hotelBillingDataRequest, history } = this.props;

    // hotelEntityDataRequest(id)

    hotelBillingDataRequest({
      hotel_id: id,
      room_id: "1",
      check_in: "01/01/2020",
      check_out: "01/01/2020",
      no_of_guests: "2",
      no_of_rooms: "2",
      membership: true,
    });

    // <Redirect to={`/entity/${id}`}/>
  };

  findFontawesome = (ele) => {
    let fa = [
      faStar,
      faPen,
      faTags,
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
      faBed,
      faCheese,
      faRestroom,
      faParking,
      faThermometerEmpty,
      faChair,
      faTv,
      faSoap,
    ];
    switch (ele) {
      case "faFan":
        return faFan;
      case "faWifi":
        return faWifi;
      case "faFire":
        return faFire;
      case "faTv":
        return faTv;
      case "faBreadSlice":
        return faBreadSlice;
      case "faToilet":
        return faToilet;
      case "faHotTub":
        return faHotTub;
      case "faParking":
        return faParking;
      case "faSoap":
        return faSoap;
      case "faBed":
        return faBed;
      case "faCheese":
        return faCheese;
      case "faHandHoldingWater":
        return faHandHoldingWater;
      case "faChair":
        return faChair;
      case "faThermometerEmpty":
        return faThermometerEmpty;
      case "faMoneyBillWave":
        return faMoneyBillWave;
      case "faMusic":
        return faMusic;
      case "faHandHoldingWater":
        return faHandHoldingWater;
      case "faBone":
        return faBone;
      case "faRestroom":
        return faRestroom;
      case "faStar":
        return faStar;
      case "faDoorClosed":
        return this.faDoorClosed;
      case "faPen":
        return faPen;
      case "faTags":
        return faTags;
      case "faCheckCircle":
        return faCheckCircle;
      case "faPersonBooth":
        return faPersonBooth;
      default:
        return faDotCircle;
    }
  };

  render() {
    let { data, mapView } = this.props;
    let address = loadData("address");

    let increseCol = mapView ? "col-12" : "col-5";
    let styles = mapView ? MapViewCss : nonMapViewCss;

    const { changeToEntityPage, findFontawesome } = this;
    console.log(data, "amenities");
    let amenities = [];
    if (data) {
      data.amenities.map((ele) => {
        if (ele.status) {
          if (amenities.length < 3) {
            amenities.push(ele);
          }
        }
      });
    }
    return (
      <>
        <div class="card mt-5 border-0" id={styles.border}>
          <div class="row no-gutters" id={styles.imgContainer}>
            <div class="col-md-4  h-100">
              <img src={data.images.random[0]} class="card-img" alt="..." id={styles.imageFit} />
            </div>
            <div className=" col-1 d-flex flex-column justify-content-center h-100" id={styles.hide}>
              <>
                <img src={data.images.random[0]} class="card-img p-1 h-25" alt="" />
                <img src={data.images.thumb[1]} class="card-img p-1 h-25" alt="" />
                <img src={data.images.random[2]} class="card-img p-1 h-25" alt="" />
                <img src={data.images.thumb[3]} class="card-img p-1 h-25" alt="" />
              </>
            </div>
            <div class="col-md-7">
              <div class="card-body" id={styles.cardBody}>
                <h5 class="card-title m-0 text-truncate" id={styles.cardTitle}>
                  <a target="_blank" href={`/entity/${data.hotel_id}`}>
                    {data.name}
                  </a>
                </h5>
                <div className="text-truncate" id={styles.location}>
                  {" "}
                  {address}{" "}
                </div>
                <div style={{ marginTop: ".2rem" }}>
                  <div className="col-12 p-0" id={styles.ratingContainer}>
                    <span id={styles.rating}>
                      <span className="text-white">4.7</span>
                      <span>
                        <FontAwesomeIcon icon={faStar} color="#fff" size="sm" />
                      </span>
                    </span>
                    <span>(32 Rating)</span>
                    <span>Excellent</span>
                  </div>
                </div>
                <div className="col-12 d-flex p-0 mt-2 " id={styles.amenity}>
                  {amenities &&
                    amenities.map((ele) => (
                      <div id={styles.amenityWrapper}>
                        <span>
                          <FontAwesomeIcon icon={findFontawesome(ele.frot_awsome)} />
                        </span>
                        <a target="_blank" href={`/entity/${data.hotel_id}`}>
                          {ele.label}
                        </a>
                      </div>
                    ))}
                  <div id={styles.amenityWrapper}>
                    <a target="_blank" href={`/entity/${data.hotel_id}`}>
                      + 11 more
                    </a>
                  </div>
                </div>
                <div id={styles.facility}>
                  <span>Included BreakFast</span>
                  <span>santised stay</span>
                  <span>operated by Eyo</span>
                </div>
                <div className="d-flex mt-3 ">
                  <div className={` ${increseCol} p-0`}>
                    <div>
                      <span id={styles.price}>&#8377; {Math.floor(data.rooms[0].actual_price) - Math.floor((Number(data.rooms[0].actual_price) * Number(data.rooms[0].discount_percentage)) / 100)}</span>
                      <span id={styles.slashPrice}>&#8377; {Math.floor(data.rooms[0].actual_price)}</span>
                      <span id={styles.percentage}>{Math.floor(data.rooms[0].discount_percentage)} % off</span>
                    </div>
                    <div id={styles.pernight}>per room per night</div>
                    {/* <div id={styles.pernight}>Checking feature-{data.checkin_features}</div> */}
                  </div>
                  <div className="col-7 d-flex align-items-center justify-content-around p-0">
                    <span className="col-6">
                      <a target="_blank" href={`/entity/${data.hotel_id}`} id={styles.whilteButton}>
                        View details
                      </a>
                    </span>
                    <div className="col-6">
                      <button id={styles.greenButton}>Book Now</button>
                    </div>
                  </div>
                </div>
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

export default connect(mapStateToProps, mapDispatchToProps)(Card);
