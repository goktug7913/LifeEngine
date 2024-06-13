# Resources

- Energy
- Materials
- Alloys
- Food
- Consumer Goods

Arbitrary resources can be added to the game via the resource data json file.

# Travel Mechanics

- Intragalactic Vectors (Hyperlane FTL)
- Warp Drive
- Sublight Propulsion

# Galaxy

- Mode: 2D, 3D
- Geometry: Elliptical, Spiral, Irregular
- Number of Stars: integer
- Number of Planets: integer (distribution across stars)

# Game Objects

- UID
- Owner UID
- Accessors UID (list)

  ## Technology

  Technology is divided into categories, each with a list of subcategories. Each subcategory has a list of technologies. Each technology has a list of prerequisites, a cost, and a list of effects.

  Tech unlock effects are divided into modifiers, unlocks, and buildings. Modifiers are applied to the game state, unlocks unlock new game objects.

  Each empire has a list of technologies that they have researched. Technologies can be traded between empires, and can be stolen through espionage. Technologies can have tiers, and can be upgraded.

  ### Physics

        - Quantum Mechanics
        - Cosmology
        - General Relativity?
        - Electromagnetism
        - Thermodynamics
        - Optics

  ### Engineering

        - Civil
        - Mechanical
        - Electrical
        - Chemical
        - Aerospace
        - Nuclear
        - Software

  ### Society

        - Economics
        - Politics
        - Sociology
        - Psychology
        - Philosophy
        - Religion

  ### Biology

        - Genetics
        - Evolution
        - Ecology
        - Physiology
        - Anatomy
        - Microbiology
        - Xenobiology

  ## Celestial Bodies

  ### Star

  - Type: Main Sequence, Red Giant, White Dwarf...
  - Connection probability: float
  - Number of planets: integer
  - Resources: ...

  ### Habitable Bodies

        ### Planet
        - Type: Terrestrial, Gas Giant, Ice Giant, Dwarf Planet
        - Atmosphere: Oxygen, Nitrogen, Carbon Dioxide, Methane, Hydrogen, Helium
        - Moons: integer
        - Resources: ...
        - Population: integer

        ### Moon
        - Type: Terrestrial, Ice, Rock
        - Atmosphere: Oxygen, Nitrogen, Carbon Dioxide, Methane, Hydrogen, Helium
        - Resources: ...
        - Population: integer

        ### Artificial Celestial Body
        - Type: Space Station, Dyson Sphere, Ringworld, Halo, Orbital Elevator
        - Resources: ...
        - Population: integer

# Civilization

- Type: Pre-Industrial, Industrial, Post-Industrial, Spacefaring, FTL, Transcendent, Post-Singularity
- Government: Democracy, Monarchy, Oligarchy, Dictatorship, Anarchy
- Economy: Capitalism, Socialism, Communism, Feudalism, Barter
- Total Population
