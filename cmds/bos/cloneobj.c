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
        printf("װ�����ݿ��ȡʧ��\n");
        return 0;
    }
    if(sizeof(myid) == 0)
    {
        printf("װ��my_id��ȡʧ��\n");
        return 0;
    }
    if(sizeof(basename) == 0)
    {
        printf("װ��base_name��ȡʧ��\n");
        return 0;
    }
    cloneobj = new(basename);
    if(!cloneobj || !objectp(cloneobj))
    {
        printf("װ������ʧ��\n");
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
        return notify_fail("�����ʽ��cloneobj װ��idȫ�� in ���\n");
    if(sscanf(arg,"%s in %s",objid,userid) != 2)
        return notify_fail("�����ʽ��cloneobj װ��idȫ�� in ���\n");
    user = find_player(userid);
    if(!user)
        return notify_fail("�Ҳ���������Ŷ��\n");
    objs = deep_inventory(user);
    for ( i=0; i<sizeof(objs); i++ )
    {
        if(objs[i]->query("id")==objid)
        {
            obj = do_clone_obj(objs[i],user,me);
            if(objectp(obj))
            {
                printf("װ����¡�ɹ���\n");
                if(!obj->move(me))
                {
                    printf("װ���ƶ�ʧ�ܣ�\n");
                    destruct(obj);
                }
            }
            else
                printf("װ����¡ʧ�ܣ�\n");
            return 1;
        }
    }

    printf("����ʧ��\n");
    return 1;
}


int help (object me)
{
    write(@HELP
ָ���ʽ: cloneobj <װ��idȫ��> in <����>

�����������һ��װ����

HELP
    );
    return 1;
}

