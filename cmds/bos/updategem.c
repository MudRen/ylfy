
nosave string *gems_level = ({
        "ϸ���",
        "�ֲڵ�",
        "��׼��",
        "���µ�",
        "������",
        "������",
        "ħ����",
        "��ʥ��",
});

nosave string *gems_level_id = ({
        "chipped",
        "flawed",
        "standard",
        "flawless",
        "prefect",
        "diwang",
        "mowang",
        "tiansheng",
});

int main(object me,string arg)
{
    int i,j;
    object *objs = all_inventory(me);
    string name,id;
    for(i=0;i<sizeof(objs);i++)
    {
        if(base_name(objs[i]) != "/clone/gem/gem")
            continue;
        name = objs[i]->query("name");
        for(j=0;j<sizeof(gems_level);j++)
        {
            if(strsrch(filter_color(name),gems_level[j])==0)
                id = gems_level_id[j]+" "+objs[i]->query("material");
        }
        objs[i]->set_name(name,({id}));
        objs[i]->save();
    }
}

