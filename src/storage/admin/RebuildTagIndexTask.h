/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef STORAGE_ADMIN_REBUILDTAGINDEXTASK_H_
#define STORAGE_ADMIN_REBUILDTAGINDEXTASK_H_

#include "storage/BaseProcessor.h"
#include "storage/admin/RebuildIndexTask.h"

namespace nebula {
namespace storage {

class RebuildTagIndexTask : public RebuildIndexTask {
public:
    explicit RebuildTagIndexTask(StorageEnv* env,
                                 TaskContext&& ctx)
        : RebuildIndexTask(env, std::move(ctx)) {}

private:
    StatusOr<IndexItems>
    getIndexes(GraphSpaceID space) override;

    kvstore::ResultCode buildIndexGlobal(GraphSpaceID space,
                                         PartitionID part,
                                         IndexID indexID,
                                         const IndexItems& items) override;
};

}  // namespace storage
}  // namespace nebula

#endif  // STORAGE_ADMIN_REBUILDTAGINDEXTASK_H_
