inherit ITEM;
void create()
{
    set_name( "����Ӣ����", ({ "yingxiong ling", "ling", "iron" }) );
    set_weight(800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
             set("long", "����һ������ͨ�������µ��������ơ� �ɷ���ǩ��������·Ӣ�����¹���\n");
            set("shaolin",1);
//����03-7-14�޸ģ��ĳɿ�����             set("no_drop","�ⶫ��������㶪����");
             set("no_get",1);
            set("no_put",1);
        set("material", "iron");
    }
    setup();
        call_out("dest", 1800);
}
void dest()
{
    object ob=environment(this_object());
    if (ob)
    if (userp(ob) && domain_file(base_name(environment(ob)))=="shaolin" ){
       if (ob->query_condition("bonze_jail")){
               destruct(this_object());
               return;
        }
            tell_object(ob, HIY "����ɮ������ȵ���ʱ���ѹ���ʩ��Ϊ�λ��������У�\n"+"ֻ��һ�����Ƽ���㣬��������ر��ӳ��������£�\n" NOR);
            ob->move("/d/nanyang/shanmen");
            message("vision",
                HIY "ֻ��ƹ��һ����������һ��������һ����\n"
                "ԭ����һ���������ļһ�Ӵ����ﱻ���˳�����\n" NOR, environment(ob), ob);
    }
    destruct(this_object());
}
int query_autoload() { return 1; }