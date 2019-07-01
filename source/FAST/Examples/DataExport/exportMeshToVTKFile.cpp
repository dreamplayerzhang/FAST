/**
 * Examples/DataExport/exportMeshToVTKFile.cpp
 *
 * If you edit this example, please also update the wiki and source code file in the repository.
 */
#include <FAST/Exporters/VTKMeshFileExporter.hpp>
#include "FAST/Importers/ImageFileImporter.hpp"
#include "FAST/Algorithms/SurfaceExtraction/SurfaceExtraction.hpp"


using namespace fast;

int main() {
    // Import CT image
    ImageFileImporter::pointer importer = ImageFileImporter::New();
    importer->setFilename(Config::getTestDataPath() + "CT/CT-Abdomen.mhd");

    // Extract surface mesh from the CT image
    SurfaceExtraction::pointer extraction = SurfaceExtraction::New();
    extraction->setInputConnection(importer->getOutputPort());
    extraction->setThreshold(400);

    // Export mesh to disk
    VTKMeshFileExporter::pointer exporter = VTKMeshFileExporter::New();
    exporter->setInputConnection(extraction->getOutputPort());
    exporter->setFilename("region_growing_result.vtk");
    exporter->setWriteNormals(true);
    exporter->update();
}
