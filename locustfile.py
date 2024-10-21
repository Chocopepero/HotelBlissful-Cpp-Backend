from locust import HttpUser, task, between

class MyUser(HttpUser):
    wait_time = between(1, 3)  # Simulate a delay between requests (1 to 3 seconds)
    host = "http://0.0.0.0:18080"  # Use the correct address and port

    @task
    def test_backend(self):
        json_data = {
            "name": "John Doe",
            "phone": "123456",
            "numAdults": 1,
            "numChildren": 0,
            "numberRooms": 1,
            "roomType": "Deluxe Room",
            "arrivalDate": "2024-10-16",
            "departureDate": "2024-10-17"
        }
        headers = {
            "Content-Type": "application/json"
        }
        response = self.client.post("/api/reserve", json=json_data, headers=headers)

        if response.status_code == 201:
            print("Success!")
        else:
            print(f"Failed with status code {response.status_code}")
            print(f"Response content: {response.text}")
