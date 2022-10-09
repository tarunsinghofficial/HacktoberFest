package com.microservices.licenseservices.dao;

import com.microservices.licenseservices.model.License;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.data.mongodb.core.query.Criteria;
import org.springframework.data.mongodb.core.query.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public class LicenseDao {
    @Autowired
    private MongoTemplate mongoTemplate;

    public List<License> findAll(){
        return mongoTemplate.findAll(License.class);
    }

    public License save(License license){
        license.setLicenseKey(String.valueOf(java.util.UUID.randomUUID()));
        return mongoTemplate.save(license);
    }

    public License delete(String licenseKey) {
        Query query = new Query();
        query.addCriteria(Criteria.where("licenseKey").is(licenseKey));
        License license = mongoTemplate.findAndRemove(query, License.class);
        mongoTemplate.remove(license);
        return null;
    }

}
