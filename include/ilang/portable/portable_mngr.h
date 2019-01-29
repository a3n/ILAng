/// \file
/// ILA Portable manager -- exporting/importing ILA to/from JSON format.

#ifndef ILANG_PORTABLE_MNGR_H__
#define ILANG_PORTABLE_MNGR_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for exporting and importing ILA portable to/from JSON
/// format.
class PortableMngr {
public:
  /// Pointer type for normal use of IlaPortableMngr.
  typedef std::shared_ptr<PortableMngr> PortableMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  PortableMngr();
  /// Default destructor.
  ~PortableMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new PortableMngr. Used for hiding implementation
  /// specific type details.
  static PortableMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Export the ILA model to the file.
  /// \param[in] m the source ILA model.
  /// \param[in] fileName the output file name for the exported ILA portable.
  /// \return Return true if export complete successfully.
  bool ExportToFile(const InstrLvlAbsPtr& m, const std::string& fileName) const;

  /// \brief Import the portable from the file and create the ILA model.
  /// \param[in] fileName the input file name for the ILA portable.
  /// \return The pointer to the ILA model, NULL if fail importing.
  InstrLvlAbsPtr ImportFromFile(const std::string& fileName) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Serialize Sort to JSON.
  json SerSort(const SortPtr& s) const;
  /// \brief Deserialize Sort from JSON.
  SortPtr DesSort(const json& j) const;

  /// \brief Serialize Expr to JSON.
  json SerExpr(const ExprPtr& e) const;
  /// \brief Deserialize Expr from JSON.
  ExprPtr DesExpr(const json& j) const;

}; // class PortableMngr

/// Pointer type for normal use of PortableMngr.
typedef PortableMngr::PortableMngrPtr PortableMngrPtr;

}; // namespace ilang

#endif // ILANG_PORTABLE_MNGR_H__
