#ifndef XPHYSICS_MATERIAL_EDITOR_H
#define XPHYSICS_MATERIAL_EDITOR_H
#pragma once

// PhysicsMaterial editor: the generic descriptor editor (inspector, undoable edits, save) with just
// the Description panel - a material is three numbers, nothing to preview.
#include "source/Tools/Editor/xeditor_descriptor_editor.h"
#include "dependencies/xLIONCore/src/physics/xlioncore_physics_material.h"

namespace xphysics_material_editor
{
    struct session : xeditor::descriptor_editor
    {
        session(xresource::full_guid Guid, e10::library::guid LibraryGuid, xgpu::device* pDevice) noexcept
            : descriptor_editor("PhysicsMaterial", Guid, LibraryGuid, pDevice)
        {
            m_Document.Load();
            BindDescriptorInspector();
            AddPanel("Description", dock::left, [this] { m_DescriptorInspector.Show(); });
        }
    };

    inline const xeditor::auto_register_resource_editor g_Registration
    { xlioncore::physics::material::type_guid_v
    , [](xresource::full_guid Guid, e10::library::guid LibraryGuid, xgpu::device* pDevice) -> std::unique_ptr<xeditor::resource_editor>
      { return std::make_unique<session>(Guid, LibraryGuid, pDevice); }
    };
}

#endif // XPHYSICS_MATERIAL_EDITOR_H
