inherit F_CLEAN_UP;
 
string status_color(int current, int max);
object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
        if (str[i]->query("id")==target)
            return str[i];
    return 0;
}
int main(object me, string arg)
{
    object ob,obj,*inv;
    mapping map_status,skill_status,ob_data,my_data;
    string *sname,*mname;
    int i,j;
 
    seteuid(ROOT_UID);
    if(!arg)     return notify_fail("ָ���ʽ: copy <����> \n");
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob || !me->visible(ob) || !living(ob)) return notify_fail("��Ҫ����˭��״̬��\n");
       
/* delete and copy skills */
    if ( mapp(skill_status = me->query_skills()) ) {
        sname  = keys(skill_status);
        j = sizeof(skill_status);
        for(i=0; i<j; i++) {
            me->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = ob->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            me->set_skill(sname[i], skill_status[sname[i]]);
        }
    }
    
/* delete and copy skill maps */
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        j = sizeof(map_status);
        for(i=0; i<j; i++) {
            me->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            me->map_skill(mname[i], map_status[mname[i]]);
        }
    }
/* delete and copy skill learned */
    if ( mapp(skill_status = me->query_learned()) ) {
        mname  = keys(skill_status);
        j = sizeof(skill_status);
        for(i=0; i<j; i++) {
            me->skill_delete(mname[i]);
        }
    }
    if ( mapp(map_status = ob->query_learned()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            skill_status=([ mname[i]: map_status[mname[i]] ]);
        }
    }
    
/* copy combat exp values */
    ob_data=ob->query_entire_dbase();
    my_data=me->query_entire_dbase();
    my_data["combat_exp"] = ob_data["combat_exp"];
    my_data["max_neili"]  = ob_data["max_neili"];
    my_data["max_jingli"] = ob_data["max_jingli"];
    my_data["neili"]      = ob_data["neili"];
    my_data["jingli"]     = ob_data["jingli"];
    my_data["max_qi"]     = ob_data["max_qi"];
    my_data["max_jing"]   = ob_data["max_jing"];
    my_data["eff_qi"]     = ob_data["eff_qi"];
    my_data["eff_jing"]   = ob_data["eff_jing"];
    my_data["qi"]         = ob_data["qi"];
    my_data["jing"]       = ob_data["jing"];
    my_data["jiali"]      = ob_data["jiali"];
    my_data["int"]        = ob_data["int"];
    my_data["con"]        = ob_data["con"];
    my_data["str"]        = ob_data["str"];
    my_data["per"]        = ob_data["per"];
    my_data["dex"]        = ob_data["dex"];
    my_data["ker"]        = ob_data["ker"];
    inv=all_inventory(me);
    for (i=0;i<sizeof(inv);i++)
        destruct(inv[i]);
    inv=all_inventory(ob);
    for (i=0;i<sizeof(inv);i++){
        obj=new(base_name(inv[i]));
        obj->move(me);
        if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") )
            obj->wield();
        else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") )
            obj->wear();
    }
/*
    ob_data=ob->query_entire_temp_dbase();
    my_data=me->query_entire_temp_dbase();
    sname=keys(ob_data);
    for (i=0;i<sizeof(ob_data);i++)
       if(sname[i]=="link_ob"
       || sname[i]=="weapon" 
       || sname[i]=="secondary_weapon" 
       || sname[i]=="armor")        continue;
       else       me->set_temp(sname[i],ob_data[sname[i]]);
*/
    write("״̬������ϡ�\n");
    return 1;
}
    
