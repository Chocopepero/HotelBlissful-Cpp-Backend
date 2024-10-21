#include <gtest/gtest.h>
#include "../server_utils/crow_all.h" // Adjust the path as necessary
#include "../hotel_backend.hpp" // Adjust the path as necessary
#include "../reservation.hpp"  // Include the header file for your reserve function
#include "../crow_functions.cpp" // Include the implementation file for your reserve function
#include "../user_db.hpp"
#include "../json_util.hpp"
const std::string kFilename = "data/reservation_records.json";
// Mock data for testing
const std::string valid_json = R"({
    "name": "John Doe",
    "phone": "123456",
    "numAdults": 1,
    "numChildren": 0,
    "numberRooms": 1,
    "roomType": "Deluxe Room",
    "arrivalDate": "2024-10-16",
    "departureDate": "2024-10-17"
})";

const std::string invalid_json = R"({
    "name": "John Doe",
    "phone": "123456"
    // Missing other required fields
})";

// Test case for valid reservation
TEST(ReserveTest, ValidReservation) {
    crow::request req;
    crow::response res;
    HotelBackend backend{kFilename};

    req.body = valid_json;
    createReservation(req, res, backend);

    EXPECT_EQ(res.code, 200);  // Assuming 200 is the success status code
    // Add more assertions as needed
}

// Test case for invalid reservation
TEST(ReserveTest, InvalidReservation) {
    crow::request req;
    crow::response res;
   
    HotelBackend backend{kFilename};

    req.body = invalid_json;
    createReservation(req, res, backend);

    EXPECT_EQ(res.code, 400);  // Assuming 400 is the error status code for invalid input
    // Add more assertions as needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}