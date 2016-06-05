# ACTempControl
Turning a dumb window AC unit into a DHT-monitored system.

It was 80 degrees with humidity in my room, so I put my window AC unit in. There's only one setting on it, which is "High Cool" dialed up to 7. It got too cold, and I had to drag out my winter comforters at night. I couldn't win. And was probably wasting a lot of electricity.

Then I got an Arduino and a DHT (temperature and humidity) sensor so that the AC runs until the temperature drops to 24C. It stays off and turns back on when the room temperature rises above 26C. The Arduino does a check every 2 minutes so that the AC isn't constantly turning on and off and breaking things. This was much better. I am cool just enough now.
