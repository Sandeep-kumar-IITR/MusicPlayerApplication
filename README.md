# Music Player — Object-Oriented Design

A C++ music-player application structured around domain models, device abstractions, factories, managers, strategies and a facade.

## Design focus

The source layout demonstrates separation of responsibilities across several components:

- **Facade:** `MusicPlayerFacade.hpp` provides a higher-level interface to the application.
- **Application orchestration:** `MusicPlayerApplication.hpp` coordinates the application workflow.
- **Core and models:** domain-level abstractions and state.
- **Devices and externals:** boundaries for playback-related dependencies.
- **Factories:** object construction behind dedicated creation logic.
- **Managers:** coordination of application resources.
- **Strategies:** interchangeable behavior behind strategy abstractions.
- **Enums:** shared typed constants.

## Repository structure

```text
.
├── core/
├── devices/
├── enums/
├── externals/
├── factories/
├── managers/
├── models/
├── strategies/
├── MusicPlayerApplication.hpp
├── MusicPlayerFacade.hpp
└── main.cpp
```

## Build and run

The repository currently includes Windows executable artifacts, but does not yet document a portable build configuration. A C++17-compatible compiler is a reasonable starting point; verify the required standard and compiler flags from the source before building.

Example with g++ (adjust source files and include paths to match the local project):

```bash
g++ -std=c++17 -I. main.cpp -o music_player
./music_player
```

On Windows, run the resulting executable from Command Prompt or PowerShell.

## Suggested engineering improvements

- Add a CMake build configuration and document the supported compiler.
- Add unit tests for facade, factory and strategy behavior.
- Document class relationships and provide a UML class diagram.
- Add sample usage and expected console output.
- Keep generated binaries out of future commits and provide reproducible build steps.

## Author

**Sandeep Kumar** · [GitHub](https://github.com/Sandeep-kumar-IITR)
