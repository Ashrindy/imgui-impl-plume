# imgui-impl-plume

A very barebones [imgui](https://github.com/ocornut/imgui) implementation for [plume](https://github.com/renderbag/plume) RHI

Requires [imgui](https://github.com/ocornut/imgui) and [plume](https://github.com/renderbag/plume)

# Usage

At initialization, you have to init the render devices and font textures of the implementation, by doing this.

```c++
ImGui::CreateContext();
// ImGui_ImplXXXX_InitForOther(window); - based on your windowing api of choice you need to always run "InitForOther"

ImGui_ImplPlume_InitInfo initInfo {
    .interface = renderInterface, // renderInterface is a variable created by the user for their rendering
    .device = renderDevice // renderDevice is a variable created by the user for their rendering
}; // Creates the init info
ImGui_ImplPlume_Init(initInfo); // Initializes the implementation
ImGui_ImplPlume_CreateFontsTexture(); // Creates the font textures for imgui
```

During rendering if only need to render the draw data

```c++
// Command List and others begin here
// ImGui_ImplXXXX_NewFrame(); - based on your windowing api of choice, you always run NewFrame before anything else
ImGui::NewFrame();

// Simple imgui window example
ImGui::Begin("Basic Window");
ImGui::Text("Hello world!");
ImGui::End();

ImGui::Render(); // Needs to run first, so that imgui renders out the windowing to the draw data
ImGui_ImplPlume_RenderDrawData(ImGui::GetDrawData(), commandList); // Renders the draw data to the screen, commandList is a variable created by the user for their rendering
//commandList->end();
```

And at the end of your program, you have to properly free the devices created

```c++
if (auto* vkDevice = dynamic_cast<plume::VulkanDevice*>(renderDevice)) vkDeviceWaitIdle(vkDevice->vk); // Optional, but better for cleanliness

ImGui_ImplPlume_Shutdown(); // Destroys and frees the devices created by the implementation

// ImGui_ImplXXXX_Shutdown(); - based on your windowing api of choice, you afterwards need to destroy its devices too
ImGui::DestroyContext(); // Then you destroy the context of imgui itself
```

# Credits

[Unleashed Recomp](https://github.com/hedge-dev/UnleashedRecomp) - Font texture creation inspired and partially taken from there
[imgui](https://github.com/ocornut/imgui) - Heavily inspired by [imgui_impl_vulkan](https://github.com/ocornut/imgui)
