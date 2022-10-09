package com.microservices.licenseservices.repository;

import com.microservices.licenseservices.model.License;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.mongodb.core.FindAndModifyOptions;
import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.data.mongodb.core.query.BasicQuery;
import org.springframework.data.mongodb.core.query.BasicUpdate;
import org.springframework.data.mongodb.core.query.Criteria;

public class CustomLicenseRepositoryImpl implements CustomLicenseRepository{

    @Autowired
    private MongoTemplate mongoTemplate;

    @Override
    public License partialUpdate(String licenseKey, String fieldName, Object fieldValue) {
        License key = mongoTemplate.findAndModify(BasicQuery.query(Criteria.where("licenseKey").is(licenseKey)), BasicUpdate.update(fieldName, fieldValue), FindAndModifyOptions.none(), License.class);
        return key;
    }

}
