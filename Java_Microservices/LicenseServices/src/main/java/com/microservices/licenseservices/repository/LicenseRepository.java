package com.microservices.licenseservices.repository;

import com.microservices.licenseservices.model.License;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;
import org.springframework.stereotype.Repository;

@Repository
public interface LicenseRepository extends MongoRepository<License, String>, CustomLicenseRepository {

    @Query("{'licenseKey': ?0 }")
    License findLicensesByLicenseKey(String licenseKey);

}
