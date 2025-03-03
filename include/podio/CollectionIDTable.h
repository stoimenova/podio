#ifndef PODIO_COLLECTIONIDTABLE_H
#define PODIO_COLLECTIONIDTABLE_H

#include <mutex>
#include <string>
#include <vector>

namespace podio {

class CollectionIDTable {

public:
  /// default constructor
  CollectionIDTable() = default;

  /// constructor from existing ID:name mapping
  CollectionIDTable(std::vector<int>&& ids, std::vector<std::string>&& names) :
      m_collectionIDs(std::move(ids)), m_names(std::move(names)){};

  /// return collection ID for given name
  int collectionID(const std::string& name) const;

  /// return name for given collection ID
  const std::string name(int collectionID) const;

  /// Check if collection name is known
  bool present(const std::string& name) const;

  /// return registered names
  const std::vector<std::string>& names() const {
    return m_names;
  };

  /// return the ids
  const std::vector<int>& ids() const {
    return m_collectionIDs;
  }

  /// register new name to the table
  /// returns assigned collection ID
  int add(const std::string& name);

  /// Prints collection information
  void print() const;

private:
  std::vector<int> m_collectionIDs{};
  std::vector<std::string> m_names{};
  mutable std::mutex m_mutex{};
};

} // namespace podio
#endif
