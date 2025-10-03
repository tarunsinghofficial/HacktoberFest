import React, { Component } from "react";
import styles from "./DetailViewCarusel.module.css";
import { connect } from "react-redux";
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

class DetailViewCarusel extends Component {
  render() {
    if (this.props.entityData) {
      const { entityData, billingData, review } = this.props;
      const { medium } = entityData.images;
      console.log(entityData, billingData, review);

      return (
        <div className="container-fluid">
          <div className="row justify-content-row">
            <div id="carouselExampleControls" class="carousel slide w-100" data-ride="carousel">
              <div className="carousel-inner">
                <div className="carousel-item active ">
                  <div className="row">
                    <img className="d-block" style={{ width: "45%" }} src={entityData ? medium[0] : "/images/bed.webp"} alt="First slide" />

                    <img className="d-block ml-1" style={{ width: "45%" }} src={entityData ? medium[1] : "/images/bed.webp"} alt="First slide" />
                    <img className="d-block ml-1" style={{ width: "9%" }} src={entityData ? medium[2] : "/images/bed.webp"} alt="First slide" />
                  </div>
                </div>
                <div className="carousel-item ">
                  <div className="row">
                    <img className="d-block" style={{ width: "45%" }} src="/images/bed.webp" alt="First slide" />

                    <img className="d-block ml-1" style={{ width: "45%" }} src={entityData ? medium[3] : "/images/bed.webp"} alt="First slide" />
                    <img className="d-block ml-1" style={{ width: "9%" }} src={entityData ? medium[4] : "/images/bed.webp"} alt="First slide" />
                  </div>
                </div>
                <div className="carousel-item ">
                  <div className="row">
                    <img className="d-block" style={{ width: "45%" }} src={entityData ? medium[5] : "/images/bed.webp"} alt="First slide" />

                    <img className="d-block ml-1" style={{ width: "45%" }} src={entityData ? medium[6] : "/images/bed.webp"} alt="First slide" />
                    <img className="d-block ml-1" style={{ width: "9%" }} src={entityData ? medium[7] : "/images/bed.webp"} alt="First slide" />
                  </div>
                </div>
              </div>
              <a className="carousel-control-prev" id={styles.wrapper} href="#carouselExampleControls" role="button" data-slide="prev">
                <div className="d-flex align-items-center justify-content-center" id={styles.ArrowContainer}>
                  <span className="carousel-control-prev-icon" id={styles.carouselArrow} aria-hidden="true"></span>
                </div>
                <span className="sr-only">Previous</span>
              </a>
              <a className="carousel-control-next" id={styles.wrapper} href="#carouselExampleControls" role="button" data-slide="next">
                <div className="d-flex align-items-center justify-content-center" id={styles.ArrowContainer}>
                  <span className="carousel-control-prev-icon" id={styles.carouselArrowRight} aria-hidden="true"></span>
                </div>
              </a>
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
});

export default connect(mapStateToProps, null)(DetailViewCarusel);
