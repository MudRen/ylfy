inherit ITEM;
int do_put(object me, object obj, object dest,int amount);
void create()
{
        set_name("ҩ��", ({ "yao dai", "dai", "bag" }));
        set_weight(500);
        set_max_encumbrance(100000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һֻ����ҩר�õĴ��ӣ��������װ������\n");
                set("value", 100000);
                set("yaodai", 1);
        }
}
int is_container() { return 1; }

void init()
{ 
        add_action("fangyao","fangyao");
}
int fangyao(string arg)
{
        string target, item;
        object obj, dest, obj2, me;
        int amount;
        me = this_player();

        if(!arg) return notify_fail("��Ҫ��ʲ�ᶫ���Ž����\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) )
                return notify_fail("����û������������\n");
        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
        if( !obj->query("yao") && !obj->query("zhuyao") )
          return notify_fail("ҩ��ֻ�ܷ�ҩ�ݣ����ܷ�����������\n");
        if( obj->query("no_put") && !wizardp(me) )
          return notify_fail("���������������š�\n");

                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > 10 ) amount = 10;
                if( obj->query_amount() ){
                        if( amount > obj->query_amount() )
                        return notify_fail("��û��������" + obj->name() + "��\n");
                        else if( amount == (int)obj->query_amount() )
                        return do_put(me, obj, dest,1);
                        else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        return do_put(me, obj2, dest,1);
                        return 1;
                        }
                }else   { do_put(me, obj, dest,amount);return 1;}
        }
        if(!objectp(obj = present(item, me)))
                return notify_fail("������û������������\n");
        return do_put(me, obj, dest,1);
}
int do_put(object me, object obj, object dest,int amount)
{
        string str,arg;
        int i;
        if( !obj->query("yao") && !obj->query("zhuyao") )
          return notify_fail("ҩ��ֻ�ܷ�ҩ�ݣ����ܷ�����������\n");
        if (obj==dest)  return notify_fail("����������Ҳ�У�\n");
        str=obj->query("id");
        arg=obj->query("unit")+obj->name();
        for (i=0;i<amount;i++){
                if( obj->move(dest) ) {
                if (!dest->query("yaodai") && obj ) 
                  destruct(obj);
              if ( sizeof(all_inventory(dest)) > 200 )
            {
                       if (!obj->move(me))     obj->move(environment(me));
                      tell_object(me,"һ��ҩ���������ֻ�ܷ�200������!\n");
                      return 1;
            }
                        if(!objectp(obj = present(str, me))) {i++;break;}
                }else{  tell_object(me,obj->name()+"��"+dest->name()+"����̫���ˡ�\n");
                        if (!obj->move(me))     obj->move(environment(me));
                        return 1;}
        }
        if( !dest->is_character() || dest->is_corpse() ){
                dest->add("no_clean_up",1);
                message_vision( sprintf("$N��%s%s�Ž�%s��\n",
                CHINESE_D->chinese_number(i),arg,dest->name()),me );
        }else{
                message_vision( sprintf("$N͵͵�ؽ�%s%s�Ž�%s�����ϡ�\n",
                CHINESE_D->chinese_number(i),arg,dest->name()),me );
        }
        return 1;
}

