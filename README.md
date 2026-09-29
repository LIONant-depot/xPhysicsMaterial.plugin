# xPhysicsMaterial.plugin

Descriptor-only resource type `PhysicsMaterial` (friction, restitution, density) - the surface properties a physics collider shape hands to Box3D. No compiler.

- `Plugin.config/resource_pipeline.config.txt` - registers the type (TypeGUID must match `xlioncore::physics::material::type_guid_v`).
- `source/Editor/xphysics_material_editor.h` - the editor: the generic descriptor editor with a Description panel.
- The descriptor, its factory and runtime loading live in xLIONCore (`src/physics/xlioncore_physics_material.h`).
