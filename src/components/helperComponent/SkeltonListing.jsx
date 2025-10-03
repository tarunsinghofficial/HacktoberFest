import React from "react";
import styles from "./card.module.css";

import Skeleton from "react-loading-skeleton";

const SkeltonListing = () => {
  return (
    <>
      <div class="card mt-5 border-0" id={styles.border}>
        <div class="row no-gutters" id={styles.imgContainer}>
          <div class="col-md-4  h-100">
            {" "}
            <div class="card-img" id={styles.imageFit}>
              <Skeleton height={260} />
            </div>
          </div>
          <div className=" col-1 d-flex flex-column justify-content-center h-100" id={styles.hide}>
            <div class="card-img p-1 h-25" alt="">
              <Skeleton height={60} />
            </div>
            <div class="card-img p-1 h-25" alt="">
              <Skeleton height={60} />
            </div>
            <div class="card-img p-1 h-25" alt="">
              <Skeleton height={60} />
            </div>
            <div class="card-img p-1 h-25" alt="">
              <Skeleton height={60} />
            </div>
          </div>
          <div class="col-md-7">
            <div class="card-body" id={styles.cardBody}>
              <h5 class="card-title m-0 text-truncate" id={styles.cardTitle}>
                <Skeleton />
              </h5>
              <h5 class="card-title m-0 text-truncate" id={styles.cardTitle}>
                <Skeleton />
              </h5>
              <div className="mt-3">
                <div className="col-12 p-0" id={styles.ratingContainer}>
                  <span>
                    <Skeleton width={35} height={20} />
                  </span>
                  <span>
                    <Skeleton width={35} height={20} />
                  </span>
                  <span>
                    <Skeleton width={35} height={20} />
                  </span>
                </div>
              </div>
              <div className="col-12 d-flex p-0 mt-2 " id={styles.amenity}>
                <div id={styles.amenityWrapper}>
                  <span>
                    <Skeleton width={45} height={20} />
                  </span>
                  <span>
                    <Skeleton width={45} height={20} />
                  </span>
                </div>
                <div id={styles.amenityWrapper}>
                  <span>
                    <Skeleton width={45} height={20} />
                  </span>
                  <span>
                    <Skeleton width={45} height={20} />
                  </span>
                </div>
              </div>
              <div>
                <span>
                  <Skeleton width={45} height={20} />
                </span>
                <span>
                  <Skeleton width={45} height={20} />
                </span>
                <span>
                  <Skeleton width={45} height={20} />
                </span>
              </div>
              <div className="d-flex mt-3 ">
                <div className={`col-5 p-0`}>
                  <div>
                    <span id={styles.price}>
                      <Skeleton width={60} height={25} />
                    </span>
                    <span id={styles.slashPrice}>
                      <Skeleton width={60} height={25} />
                    </span>
                    <span id={styles.percentage}>
                      <Skeleton width={60} height={25} />
                    </span>
                  </div>
                </div>
                <div className="col-7 d-flex align-items-center justify-content-around p-0">
                  <div className="col-6">
                    <div target="_blank">
                      <Skeleton height={55} />
                    </div>
                  </div>
                  <div className="col-6">
                    <div>
                      <Skeleton height={55} />
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </>
  );
};
export default SkeltonListing;
