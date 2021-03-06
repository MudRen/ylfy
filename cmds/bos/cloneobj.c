#include <color.h>

inherit F_CLEAN_UP;

void create()
{
    seteuid(getuid());
}

object do_clone_obj(object obj,object from,object to)
{
    string basename;
    mapping dbase;
    string* myid;
    object cloneobj;
    string *keys;
    int i,sz;

    dbase = obj->query_entire_dbase();
    basename = base_name(obj);
    myid = obj->parse_command_id_list();
    if(!mapp(dbase))
    {
        printf("装备数据库获取失败\n");
        return 0;
    }
    if(sizeof(myid) == 0)
    {
        printf("装备my_id获取失败\n");
        return 0;
    }
    if(sizeof(basename) == 0)
    {
        printf("装备base_name获取失败\n");
        return 0;
    }
    cloneobj = new(basename);
    if(!cloneobj || !objectp(cloneobj))
    {
        printf("装备创建失败\n");
        return 0;
    }
    cloneobj->delete("female_only");
    keys = keys(dbase);
    sz = sizeof(keys);
    for(i=0;i<sz;i++)
    {
        cloneobj->set(keys[i],dbase[keys[i]]);
    }
    cloneobj->set_name(dbase["name"],myid);
    cloneobj->delete("equipped");
    cloneobj->delete("bind_master_level/"+from->query("id"));
    cloneobj->set("bind_master_level/"+to->query("id"),2);
    return cloneobj;

}
int main(object me, string arg)
{
    string objid,userid;
    object user,obj;
    object *objs;
    int i;

    if( !arg )
        return notify_fail("命令格式：cloneobj 装备id全名 in 玩家\n");
    if(sscanf(arg,"%s in %s",objid,userid) != 2)
        return notify_fail("命令格式：cloneobj 装备id全名 in 玩家\n");
    user = find_player(userid);
    if(!user)
        return notify_fail("找不到这生物哦。\n");
    objs = deep_inventory(user);
    for ( i=0; i<sizeof(objs); i++ )
    {
        if(objs[i]->query("id")==objid)
        {
            obj = do_clone_obj(objs[i],user,me);
            if(objectp(obj))
            {
                printf("装备克隆成功！\n");
                if(!obj->move(me))
                {
                    printf("装备移动失败！\n");
                    destruct(obj);
                }
            }
            else
                printf("装备克隆失败！\n");
            return 1;
        }
    }

    printf("操作失败\n");
    return 1;
}


int help (object me)
{
    write(@HELP
指令格式: cloneobj <装备id全名> in <生物>

复制玩家身上一件装备。

HELP
    );
    return 1;
}

