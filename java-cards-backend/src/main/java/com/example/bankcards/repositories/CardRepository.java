package com.example.bankcards.repositories;

import com.example.bankcards.models.Card;
import org.springframework.data.mongodb.repository.MongoRepository;

public interface CardRepository extends MongoRepository<Card, String> {
}
