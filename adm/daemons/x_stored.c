// /adm/daemons/x_stored.c ����װ���ػ�����

inherit F_DBASE;

#define ban_time    2           //���Ƽ��ʱ��
#define user_pay    5           //��ȡ��������
#define item_min    100          //��С������������ÿ�����ݶ�ȣ�
#define item_max    100         //�������������ÿ����Ʒ���ޣ�
#define chawu_cmd   "chawu"     //�������ָ��
#define chuwu_cmd   "chuwu"     //���崢��ָ��
#define quwu_cmd    "quwu"      //����ȡ��ָ��
#define augment_cmd "augment"   //��������ָ��
#define user_mark   "time/use_chuwu"                        //�����û����
#define ban_msg     "�ռ������У����Ժ����г��ԡ�\n"        //��������ѶϢ

public int do_chawu(object me, object ob);                  //�鿴�洢��Ʒ���������������ã�
public int do_chuwu(object me, object ob, string arg);      //������Ʒ�洢���������������ã�
public int do_quwu(object me, object ob, string arg);       //ȡ���洢��Ʒ���������������ã�
public int do_augment(object me, object ob);                //���пռ����ݣ��������������ã�
public int query_min();                                     //��ѯ�ռ����ޣ��������������ã�
public string cmds_help();                                  //��ȡָ��������������������ã�
public string *able_cmds();                                 //��ȡָ���б��������������ã�
private int ban_user(object me, object ob);                 //У���û�����
private int do_put(object me, object obj, object ob);       //ִ�д��ﶯ��
private int do_get(object me, object ob, string arg);       //ִ��ȡ�ﶯ��
private void confirm_aug(string yn, object me, object ob);  //ȷ�Ͽռ�����
private void save_data(object me, object ob);               //������Ӧ����
private void msg_info(string msg);                          //����Ƶ��ѶϢ

void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "�����ػ�");
}

//����Ƶ��ѶϢ
private void msg_info(string msg)
{
    CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

//У���û�����
private int ban_user(object me, object ob)
{
    int now, old;
    string str;

    if(!ob->query("item_max") || ob->query("item_max") <= 0)
        ob->set("item_max", item_min);  //��ʼ����������

    now = time() & 0xFFFFFFFE;                      //��ǰʱ��ȡֵ
    old = me->query(user_mark) & 0xFFFFFFFE;        //�û����ȡֵ
    str = ob->query("def_name");                    //����Ĭ������
    if(now - old < ban_time)                        //δ������ʱ��
    {
        tell_object(me, str + ban_msg);             //��������ѶϢ
        return 1;
    }

    return 0;
}

//������Ӧ���ݣ��淢����ӦѶϢ��
private void save_data(object me, object ob)
{
    int num;
    mapping tmp;
    string msg, str;

    tmp = ob->query_temp("msg");    //��ʱѶϢӳ��
    if(mapp(tmp) && sizeof(tmp) == 3)
    {

        str = tmp["text"];
        num = tmp["time"];
        msg = replace_string(str, ob->name(), ob->query("def_name"));
        msg = replace_string(msg, me->name(), "��");
        msg = replace_string(msg, "һЩ", sprintf("%s%s",
                                chinese_number(num), tmp["unit"]));
        tell_object(me, msg);                       //�����û�ѶϢ
        if(num == 1)
            str = replace_string(str, "һЩ", sprintf("%s%s",
                                chinese_number(num), tmp["unit"]));
        tell_room(environment(me), str, ({ me }));  //���ͻ���ѶϢ
    }
    if(ob->query_temp("msg"))
        ob->delete_temp("msg");                     //�����ʱӳ��
    me->set(user_mark, time() & 0xFFFFFFFE);        //�����û����
    me->save(); //�û��浵
    ob->save(); //�����浵
}

//�鿴�洢��Ʒ���������������ã�
public int do_chawu(object me, object ob)
{
    mapping obs;
    string msg, str, *key;
    int i, j, x, num, max, use;

    if(ban_user(me, ob))            //У���û�����
        return 1;

    str = ob->query("def_name");    //����Ĭ������
    max = ob->query("item_max");    //������������
    use = ob->query("item_use");    //�������ø���
    obs = ob->query("item_list");   //������Ʒ�б�
    msg = sprintf("���%s�����ȼ���%-2d ��    ������%3d / %-3d��\n",
                    str, (max/item_min), use, max);
    msg += sprintf("%s\n", repeat_string("=", 80));
    if(!mapp(obs) || sizeof(obs) <= 0)
    {
        msg += sprintf("%s�����ǿյġ�\n", str);
        tell_object(me, msg);
        return 1;
    }

    key = keys(obs);    //��Ʒ�б��ֵ����
    msg += sprintf("���%s��Ʒ%s��λ  ����\n", repeat_string(" ", 4), repeat_string(" ", 50));
    msg += sprintf("%s\n", repeat_string("-", 80));
    for(i = 0, j = 0; i < sizeof(key); i++)
    {
        num = obs[key[i]]["nums"];  //��Ӧ��Ʒ����
        j += num;                   //��¼��Ʒ����
        if(num > item_max)  //��Ʒ��������һ��
        {
            x = (num / item_max) + 1;   //����Ʒռ�ø�������ѭ����ʾ
            while(x--)
            {
                if(x > 0)   //ѭ����ʾ����ĸ���Ʒ
                    msg += sprintf("%-60s%-4s  %-d\n",
                                    obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                                    obs[key[i]]["unit"], item_max);
                else
                    if((num % item_max) > 0)    //���������㣬����ʾ����
                        msg += sprintf("%-60s%-4s  %-d\n",
                                        obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                                        obs[key[i]]["unit"], (num % item_max));
            }
        }
        else
            msg += sprintf("%-60s%-4s  %-d\n",
                            obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                            obs[key[i]]["unit"], obs[key[i]]["nums"]);
    }
    msg += sprintf("%s\n", repeat_string("-", 80));
    msg += sprintf("���� %d ����Ʒ���ϼ� %d ����\n", sizeof(key), j);
    me->set(user_mark, time() & 0xFFFFFFFE);        //�����û����
    me->start_more(msg);                            //�����û�ѶϢ
    return 1;
}

//������Ʒ�洢���������������ã�
public int do_chuwu(object me, object ob, string arg)
{
    int i, amount;
    string str, item;
    object obj, obj2, *inv;

    str = ob->query("def_name");    //����Ĭ������
    if(!arg)
    {
        tell_object(me, sprintf("��Ҫ��ʲôװ��%s��\n", str));
        return 1;
    }

    if(ban_user(me, ob))            //У���û�����
        return 1;

    //�������Ĵ洢��ָ���ʽ������ ���� ID��
    if(sscanf(arg, "%d %s", amount, item) == 2)
    {
        if(!objectp(obj = present(item, me)))
        {
            tell_object(me, "������û������������\n");
            return 1;
        }

        if(amount < 1)
        {
            tell_object(me, "��Ʒ������������һ����\n");
            return 1;
        }

        if(amount > item_max)
        {
            tell_object(me, sprintf("ÿ�δ��������������%s����\n",
                                        chinese_number(item_max)));
            return 1;
        }

        if(obj->query_amount() && !obj->query("armor_prop/armor") //װ��
            && !obj->query("weapon_prop/damage") ) //�ɺϲ������
        {			
            if(amount > obj->query_amount())        //������������ӵ������
            {
                tell_object(me, sprintf("��û����ô���%s��\n", obj->name(1)));
                return 1;
            }
            else
                if(amount == obj->query_amount())   //������������ӵ������
                    return do_put(me, obj, ob);
            else                                    //��������С��ӵ������
            {
                obj2 = new(base_name(obj)); //!!!�˴��д����ƣ���Ʒ�������ݣ�
                obj2->set_amount(amount);   //�趨�洢����
                if(do_put(me, obj2, ob))    //�洢ִ�гɹ�
                {                           //�˼���Ӧ����
                    obj->set_amount(obj->query_amount() - amount);
                    return 1;
                }
                else
                    return 0;
            }
        }
        else    //���ɺϲ����
        {
            inv = all_inventory(me);    //�û���Я��Ʒ
            inv = filter_array(inv, (: member_array($(item),
                                $1->parse_command_id_list()) != -1 :));     //ɸѡID�����
            inv = filter_array(inv, (: $1->name(1) == $(obj)->name(1) :));  //ɸѡ�������
            if(amount > sizeof(inv))    //������������ӵ������
            {
                tell_object(me, sprintf("��û����ô���%s��\n", obj->name(1)));
                return 1;
            }
            else 
            {   //����ӵ����������ѭ������
                for(i = 0; i < sizeof(inv); i++)
                {
                    reset_eval_cost();
                    obj2 = inv[i];
                    if(!do_put(me, obj2, ob))   //��������ʧ�ܣ�ѭ��������ֹ
                        break;
                        
                }
                save_data(me, ob);  //������Ӧ����
                return 1;
            }
        }
    }

    //���������洢��ָ���ʽ������ ID��
    if(!objectp(obj = present(arg, me)))
    {
        tell_object(me, "������û������������\n");
        return 1;
    }

    do_put(me, obj, ob);    //ִ�д��ﶯ��
    save_data(me, ob);      //������Ӧ����
    return 1;
}

//ִ�д��ﶯ��
private int do_put(object me, object obj, object ob)
{
    object *inv;
    string str, arg, *key, slot;
    mapping obs, tmp, msg;
    int num, max, use, xxx, yyy, zzz, i;

    str = ob->query("def_name");    //����Ĭ������
    if(obj == ob)   //����
    {
        tell_object(me, sprintf("��ͼ��%sװ����������²����޸���"
                                "�𻵣���С��ʹ�á�\n", str));
        return 0;
    }

    if(obj->query("no_put")                 //��������
        || obj->query("no_drop")            //���ɶ���
        || obj->query("no_get")             //����ʰȡ
        || obj->query("no_leave")           //��������
        || obj->query("id") == "mailbox")   //��������
    {
        tell_object(me, sprintf("%s�����뿪�㡣\n", obj->name(1)));
        return 0;
    }

    if(obj->is_character() || obj->query("ride_prop"))  //���˻���ƥ
    {
        tell_object(me, sprintf("���ﲻ��װ��%s��\n", str));
        return 0;
    }

    if(obj->query("money_id")           //��Ǯ
        || obj->query("food_supply")    //ʳ��
        || obj->query("start_fulan")    //����
        || obj->query("quest_ob")       //����
        || obj->query("id") == "corpse" //ʬ��
		|| obj->query("yao")    //ҩ
		|| obj->query("zhuyao")    //��ҩ
        || obj->query("id") == "pate"//�׼�
		)  
    {
        tell_object(me, sprintf("%s���Ǳ����䣬���Ǳ��ʹ�����Ͱ,����װ��%s��\n",
                                    str, obj->name(1)));
        return 0;
    }

    if(me->query("neili") < user_pay)   //��������֧������
    {
        tell_object(me, sprintf("��������������޷���%s����%s��\n",
                                    obj->name(1), str));
        return 0;
    }

    if(obj->query("equipped"))          //�������װ��״̬
    {
        tell_object(me, sprintf("���Ƚ��%s��װ��״̬�������޷�����%s��\n",
                                    obj->name(1), str));
        return 0;
    }
    if(!obj->query("value") && !obj->value() )          //û�м�ֵ����Ʒ
    {
        tell_object(me, sprintf("%s���Ǳ����䣬���Ǳ��ʹ�����Ͱ,����װ��%s��\n",
                                    obj->name(1), str));
        return 0;
    }
	
    inv = all_inventory(obj);
    if(sizeof(inv))                     //�������װ����Ʒ
    {
        tell_object(me, sprintf("�������%s�ڵ���Ʒ�������޷�����%s��\n",
                                    obj->name(1), str));
        return 0;
    }

    if(!mapp(ob->query("item_list")))   //��������Ʒ�б�
        ob->set("item_list", ([]));     //��ʼ����Ʒ�б�
    obs = ob->query("item_list");       //������Ʒ�б�
    if(sizeof(obs) > 0)
        key = keys(obs);    //������Ʒ�б��ֵ����
    else
        key = ({  });       //��Ʒ�б��ֵ����Ϊ��
    xxx = obj->query_amount() ? obj->query_amount() : 1;
    arg = obj->query("id");             //��ƷIDΪ��ֵ
    max = ob->query("item_max");        //������������
    use = ob->query("item_use");        //�������ø���

    i = sizeof(key);
    if ( !obj->query("armor_prop/armor") //װ��
        && !obj->query("weapon_prop/damage") )
    {
        for ( i = 0; i < sizeof(key); i++ )
        {
            if ( arg == obs[key[i]]["primary_id"] )
            {
                slot = key[i];
                break;
            }
        }
    }

    if ( i >= sizeof(key) )  //����δ�и���
    {
        if(use >= max)
        {
            tell_object(me, str + "����Ʒ���ѵ����ޣ��޷���������Ʒ���ˡ�\n");
            return 0;
        }

        for ( i = 0; i < max; i++ )
        {
            slot = sprintf("%d", i);
            if ( member_array(slot, key) == -1 )
            {
                break;
            }
        }

        tmp = ([    slot    : ([     //��ƷIDΪ��ֵ
                    "primary_id" : arg,
    /*ID�б�*/        "id" : obj->parse_command_id_list(),
    /*��Ʒ����*/    "name" : obj->name(1),
    /*������λ*/    "unit" : obj->query("unit") ? obj->query("unit") : "��",
    /*��ϸ����*/    "long" : obj->query("long"),
    /*��Ʒ����*/    "nums" : obj->query_amount() ? obj->query_amount() : 1,
    /*��׼�ļ�*/    "file" : base_name(obj),
    /*��������*/    "data" : obj->query_entire_dbase(),
               ]), ]);
        obs += tmp;                 //��¼��Ʒ����
        ob->set("item_list", obs);  //������Ʒ�б�
        ob->add("item_use", 1);     //����ռ�ø���
    }
    else    //�������и���
    {
        tmp = obs[slot];     //��ȡԭ����Ʒ��Ϣ
        num = tmp["nums"];  //��ȡԭ����Ʒ����
        if(num + xxx > item_max)    //��ԭ����������������һ��
        {
            yyy = (num / item_max) + 1;         //ԭ������ռ�ø���
            if((num % item_max) == 0)           //������������Ϊ��
                yyy -= 1;                       //ռ�ø����ټ�һ��

            zzz = ((num + xxx) / item_max) + 1; //����֮��ռ�ø���
            if(((num + xxx) % item_max) == 0)   //������������Ϊ��
                zzz -= 1;                       //ռ�ø����ټ�һ��

            if((use - yyy + zzz) > max)   //�����ռ�ø����ᳬ�ޣ�����ʾ�޷�����
            {
                tell_object(me, sprintf("%s�Ĵ��������������Ѿ��޷��ٷ���"
                                        "%s�ˡ�\n", str, obj->name(1)));
                return 0;
            }
        }
        else
            zzz = 0;    //��ԭ��������Ӳ�����һ�飬�����ռ����

        num += xxx;                     //������Ʒ����
        obs[slot]["nums"] = num;         //������Ʒ����
        ob->set("item_list", obs);      //������Ʒ�б�
        if(zzz > 0)                     //����ռ�ø���������󳬹�һ��������
            ob->set("item_use", use - yyy + zzz);   //����ԭռ������������ռ����
    }

//����ʱӳ���¼�跢��ѶϢ--------------------------------------------Top------
    msg = ob->query_temp("msg");
    if(!mapp(msg))
        msg = ([]);
    if(!stringp(msg["unit"]))   //������λ
        msg["unit"] = obj->query("unit") ? obj->query("unit") : "��";
    if(!stringp(msg["text"]))   //����ѶϢ
        msg["text"] = sprintf("%s��һЩ%sװ��%s��\n",
                                me->name(), obj->name(1), ob->name(1));
    if(!intp(msg["time"]))      //ѭ������
        msg["time"] = 0;
    msg["time"] += xxx;
//����ʱӳ���¼�跢��ѶϢ--------------------------------------------End------

    ob->set_temp("msg", msg);       //��¼ѶϢӳ��
    me->add("neili", -user_pay);    //�۳���������
    destruct(obj);                  //����ԭ����Ʒ
    return 1;
}

//ȡ���洢��Ʒ���������������ã�
public int do_quwu(object me, object ob, string arg)
{
    mapping obs;
    int i, amount, num;
    string str, item, *key, slot;

    str = ob->query("def_name");    //����Ĭ������
    if(!arg)
    {
        tell_object(me, sprintf("��Ҫ��%s��ȡ��ʲô��\n", str));
        return 1;
    }

    if(ban_user(me, ob))            //У���û�����
        return 1;

    obs = ob->query("item_list");   //������Ʒ�б�
    if(!mapp(obs) || sizeof(obs) <= 0)
    {
        tell_object(me, sprintf("%s�����ǿյġ�\n", str));
        return 1;
    }

    key = keys(obs);
    //��������ȡ�ָ���ʽ��ȡ�� ���� ID��
    if(sscanf(arg, "%d %s", amount, item) == 2)
    {
        for ( i = 0; i < sizeof(key); i++ )
        {
            if ( item == obs[key[i]]["primary_id"] )
            {
                slot = key[i];
                break;
            }
        }
        if ( i >= sizeof(key) )
        {
            tell_object(me, sprintf("%s�ﲢδ���� %s ������Ʒ��\n", str, item));
            return 1;
        }

        if(amount < 1)
        {
            tell_object(me, "��Ʒ������������һ����\n");
            return 1;
        }

        if(amount > item_max)
        {
            tell_object(me, sprintf("ÿ��ȡ�������������%s����\n",
                                        chinese_number(item_max)));
            return 1;
        }

        num = obs[slot]["nums"];    //��Ʒ��������
        if(amount > num)
        {
            tell_object(me, sprintf("%s��û�д�����ô���%s��\n",
                                        str, obs[slot]["name"]));
            return 1;
        }
        else
        {   //��������ѭ��ִ��ȡ��
            for(i = 0; i < amount; i++)
            {
                reset_eval_cost();
                if(!do_get(me, ob, item))   //����ȡ��ʧ�ܣ�ѭ��������ֹ
                    break;
            }
            save_data(me, ob);  //������Ӧ����
            return 1;
        }
    }
    //��������ȡ�ָ���ʽ��ȡ�� ID��
    do_get(me, ob, arg);    //ִ��ȡ�ﶯ��
    save_data(me, ob);      //������Ӧ����
    return 1;
}

//ִ��ȡ�ﶯ��
private int do_get(object me, object ob, string arg)
{
    object obj;
    mapping obs, tmp, msg;
    string str, *key, slot;
    int i, num, use, xxx, yyy, zzz;

    str = ob->query("def_name");    //����Ĭ������
    obs = ob->query("item_list");   //������Ʒ�б�
    key = keys(obs);                //��Ʒ�б��ֵ����

    for ( i = 0; i < sizeof(key); i++ )
    {
        if ( arg == obs[key[i]]["primary_id"] )
        {
            slot = key[i];
            break;
        }
    }

    if ( i >= sizeof(key) )
    {
        tell_object(me, sprintf("%s�ﲢδ���� %s ������Ʒ��\n", str, arg));
        return 0;
    }

    if(me->query("neili") < user_pay)   //��������֧������
    {
        tell_object(me, sprintf("�������̫�٣��޷���%s��ȡ����Ʒ��\n", str));
        return 0;
    }

    tmp = obs[slot];                         //��ȡ��Ӧ����
    obj = new(tmp["file"]);                 //�����������
    obj->set_name(tmp["name"], tmp["id"]);  //��ԭ������ID

    tmp = obs[slot]["data"];                 //��ȡ�浵����
    key = keys(tmp);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == "id")                  //������ֵID
            continue;
        obj->set(key[i], tmp[key[i]]);      //��ԭ�������
    }
    obj->move(me);                          //��Ʒ�ƽ��û�

    xxx = obj->query_amount() ? obj->query_amount() : 1;
    num = obs[slot]["nums"];         //��Ӧ��Ʒ����
    use = ob->query("item_use");    //������ռ����
    if(num == 1)                    //��Ʒ����һ��
    {
        zzz = -1;                   //ռ�ø�����һ
        map_delete(obs, slot);       //ɾ���浵����
    }
    else                            //��Ʒ��ֹһ��
    {
        if(num > item_max)          //��Ʒ��������һ��
        {
            yyy = (num / item_max) + 1;         //ԭ������ռ�ø���
            if((num % item_max) == 0)           //������������Ϊ��
                yyy -= 1;                       //ռ�ø����ټ�һ��

            zzz = ((num - xxx) / item_max) + 1; //����֮��ռ�ø���
            if(((num - xxx) % item_max) == 0)   //������������Ϊ��
                zzz -= 1;                       //ռ�ø����ټ�һ��

        }
        else                        //��Ʒ��������һ��
            zzz = 0;                //ռ�ø�������

        num -= 1;                   //������Ӧ����
        obs[slot]["nums"] = num;     //������Ʒ����
    }

    if(zzz != 0)                                //ռ�ø����б�
        ob->set("item_use", use - yyy + zzz);   //У׼ռ�ø���
    ob->set("item_list", obs);                  //������Ʒ�б�

//����ʱӳ���¼�跢��ѶϢ--------------------------------------------Top------
    msg = ob->query_temp("msg");
    if(!mapp(msg))
        msg = ([]);
    if(!stringp(msg["unit"]))   //������λ
        msg["unit"] = obj->query("unit") ? obj->query("unit") : "��";
    if(!stringp(msg["text"]))   //����ѶϢ
        msg["text"] = sprintf("%s��%s��ȡ��һЩ%s��\n",
                                me->name(), ob->name(1), obj->name(1));
    if(!intp(msg["time"]))      //ѭ������
        msg["time"] = 0;
    msg["time"] += xxx;
//����ʱӳ���¼�跢��ѶϢ--------------------------------------------End------

    ob->set_temp("msg", msg);       //��¼ѶϢӳ��
    me->add("neili", -user_pay);    //�۳���������
    return 1;
}

//���пռ����ݣ��������������ã�
public int do_augment(object me, object ob)
{
    int now, max, pay;
    string msg, str;

    if(ban_user(me, ob))            //У���û�����
        return 1;

    str = ob->query("def_name");    //����Ĭ������
    now = ob->query("item_max");    //��ǰ�ȼ�����
    if(now >= item_max)             //�����Ѵ�����
    {
        msg = sprintf("\n���%s�ѵ�����������ޣ��޷��������ȼ��ˡ�\n", str);
        tell_object(me, msg);
        return 1;
    }

    max = now + item_min;                           //��һ�ȼ�����
    pay = (max / item_min) * item_min * item_max / 500;   //�����������
    msg = sprintf("\n���%s��ǰ�ȼ�Ϊ%s��������%s�񣩣�������%s������"
                  "��%s����Ҫ����%s�����ƽ��Ƿ�ȷ��(Yes/No)��\n",
                    str, chinese_number(now/item_min),
                    chinese_number(now), chinese_number(max/item_min),
                    chinese_number(max), chinese_number(pay));
    msg = sort_string(msg, 64, 0);
    tell_object(me, msg);               //�û���ʾѶϢ
    input_to("confirm_aug", me, ob);    //ȷ�Ͽռ�����
    return 1;
}

//ȷ�Ͽռ�����
private void confirm_aug(string yn, object me, object ob)
{
    int now, max, pay;
    string msg, str;

    str = ob->query("def_name");    //����Ĭ������
    if(yn[0] != 'y' && yn[0] != 'Y')
    {
        tell_object(me, sprintf("\n������˶�%s����������\n", str));
        return;
    }

    now = ob->query("item_max");                    //��ǰ�ȼ�����
    max = now + item_min;                           //��һ�ȼ�����
    pay = (max / item_min) * item_min * item_max/500;   //�����������
    if(me->query("more_money") < pay)                //����֧��
    {
        msg = sprintf("\n���Ǯׯ����֧��%s����������%s�����ƽ�"
                      "��湻Ǯ������\n", str, chinese_number(pay));
        tell_object(me, msg);
        return;
    }

    me->add("more_money", -pay); //֧�����ݷ���
    ob->set("item_max", max);   //�����µ�����
    save_data(me, ob);          //������Ӧ����

    msg = sprintf("\n�㻨��%s�����ƽ�%s��������%s��������%s�񣩡�\n",
                    chinese_number(pay), str,
                    chinese_number(max/item_min),
                    chinese_number(max));
    tell_object(me, msg);       //�û���ʾѶϢ

    msg = replace_string(msg, "\n", "");
    msg = replace_string(msg, "��", "��˵ĳ��");
    msg_info(msg);              //����Ƶ��ѶϢ
    return;
}

//ָ���Ӧ����
static mapping item_cmds = ([
    augment_cmd : sprintf("�ȼ�������%s �����%s����",
                            augment_cmd, chinese_number(item_max/item_min)),
    chawu_cmd   : sprintf("�鿴���ݣ�%s", chawu_cmd),
    chuwu_cmd   : sprintf("������Ʒ��%s [����] <��ƷID>", chuwu_cmd),
    quwu_cmd    : sprintf("ȡ����Ʒ�� %s [����] <��ƷID>", quwu_cmd),
]);

//��ȡָ��������������������ã�
public string cmds_help()
{
    int i;
    string msg, *key;

    msg = sprintf("\n��%s�����������з���˾���죬���λ�����С�\n", MUD_NAME);
    key = sort_array(keys(item_cmds), 1);
    for(i = 0; i < sizeof(key); i++)
        msg += sprintf("%s\n", item_cmds[key[i]]);
    msg += "\n";
    return msg;
}

//����ָ���б��������������ã�
public string *able_cmds()
{
    return sort_array(keys(item_cmds), 1);
}

//��ѯ�ռ����ޣ��������������ã�
public int query_min()
{
    return item_min;
}
