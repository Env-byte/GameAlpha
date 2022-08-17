create schema GameAlpha;
use GameAlpha;
create table rarity_odds
(
    `id`          int auto_increment primary key,
    `probability` decimal(2, 1) default 1.0 comment 'odds of showing in shop 0.1 being almost never, 1 very high. increased by luck' not null,
    `name`        varchar(50)                                                                                                        not null,
    constraint rarity_odds_id_uindex
        unique (id)
);

insert into rarity_odds (`probability`, `name`)
VALUES (0.75, 'Common');
insert into rarity_odds (`probability`, `name`)
VALUES (0.55, 'Uncommon');
insert into rarity_odds (`probability`, `name`)
VALUES (0.35, 'Rare');
insert into rarity_odds (`probability`, `name`)
VALUES (0.15, 'Legendary');

create table stats
(
    `id`   int auto_increment primary key,
    `name` varchar(50) not null,
    constraint stats_id_uindex
        unique (id)
);
insert into stats (name)
VALUES ('Physical');
insert into stats (name)
VALUES ('Magical');
insert into stats (name)
VALUES ('Health');
insert into stats (name)
VALUES ('Defense');
insert into stats (name)
VALUES ('Luck');


create table bosses
(
    `id`   int auto_increment primary key,
    `name` varchar(50) not null,
    constraint bosses_id_uindex
        unique (id)
);

insert into bosses(`name`)
VALUES ('Demogorgan');
insert into bosses(`name`)
VALUES ('Demodog');
insert into bosses(`name`)
VALUES ('Demobats');
insert into bosses(`name`)
VALUES ('Mindflayer');
insert into bosses(`name`)
VALUES ('Vecna');

CREATE function get_boss_id(type varchar(50))
    RETURNS int
    reads SQL DATA
BEGIN
    DECLARE boss_id int;
    SELECT id into boss_id FROM bosses WHERE lower(name) = lower(type);
    return boss_id;
end;

CREATE function get_rarity_id(type enum ('Common','Uncommon','Rare','Legendary'))
    RETURNS int
    reads SQL DATA
BEGIN
    DECLARE rarity_id int;
    SELECT id into rarity_id FROM rarity_odds WHERE name = type;
    return rarity_id;
end;


CREATE function get_stat_id(type enum ('Physical','Magical','Health','Defense','Luck'))
    RETURNS int
    reads SQL DATA
BEGIN
    DECLARE stat_id int;
    SELECT id into stat_id FROM stats WHERE name = type;
    return stat_id;
end;

create table users
(
    `id`     int auto_increment primary key,
    `name`   varchar(50)                                                not null,
    `level`  int(2) default 1                                           not null,
    `bossNo` int(3) default 1 comment 'current number of bosses killed' not null,
    constraint users_id_uindex
        unique (id)
);

create table items
(
    `id`       int auto_increment primary key,
    `name`     varchar(50)      not null,
    `value`    int(2) default 1 not null,
    `rarityID` tinyint(1)       not null,
    `statID`   tinyint(1)       not null,
    `cost`     int(3) default 1 not null,
    `passive`  varchar(150),
    constraint items_id_uindex
        unique (id)
);

create table abilities
(
    `id`       int auto_increment primary key,
    `name`     varchar(50)               not null,
    `damage`   int(3)        default 1   not null comment 'current number of bosses killed',
    `scale`    decimal(2, 1) default 1.0 not null comment 'damage scale with physical or magical',
    `rarityID` tinyint(1)                not null,
    `statID`   tinyint(1)                not null comment 'the type of damage this scales with',
    constraint users_id_uindex
        unique (id)
);

insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Ice Spike', 70, 0.6, get_rarity_id('Common'), get_stat_id('Magical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Ice Ball', 90, 0.8, get_rarity_id('Uncommon'), get_stat_id('Magical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Fireball', 100, 1.1, get_rarity_id('Rare'), get_stat_id('Magical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Flamethrower', 150, 1.6, get_rarity_id('Legendary'), get_stat_id('Magical'));

insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Jab', 70, 0.6, get_rarity_id('Common'), get_stat_id('Physical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Side Kick', 90, 0.8, get_rarity_id('Uncommon'), get_stat_id('Physical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Scissor Kick', 100, 1.1, get_rarity_id('Rare'), get_stat_id('Physical'));
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('God Punch', 150, 1.6, get_rarity_id('Legendary'), get_stat_id('Physical'));


create table boss_stats
(
    bossID int           not null,
    statID int           not null,
    value  decimal(6, 2) not null,
    constraint boss_stats_index
        unique (bossID, statID)
);

insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demogorgan'), get_stat_id('Physical'), 40.50);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demogorgan'), get_stat_id('Magical'), 20);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demogorgan'), get_stat_id('Health'), 500);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demogorgan'), get_stat_id('Defense'), 15);

insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demodog'), get_stat_id('Physical'), 40.50);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demodog'), get_stat_id('Magical'), 20);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demodog'), get_stat_id('Health'), 500);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demodog'), get_stat_id('Defense'), 15);

insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demobats'), get_stat_id('Physical'), 40.50);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demobats'), get_stat_id('Magical'), 20);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demobats'), get_stat_id('Health'), 500);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Demobats'), get_stat_id('Defense'), 15);

insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Mindflayer'), get_stat_id('Physical'), 40.50);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Mindflayer'), get_stat_id('Magical'), 20);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Mindflayer'), get_stat_id('Health'), 500);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Mindflayer'), get_stat_id('Defense'), 15);

insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Vecna'), get_stat_id('Physical'), 40.50);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Vecna'), get_stat_id('Magical'), 20);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Vecna'), get_stat_id('Health'), 500);
insert into boss_stats(`bossID`, `statID`, `value`)
VALUES (get_boss_id('Vecna'), get_stat_id('Defense'), 15);

create table user_items
(
    `userID` int auto_increment primary key,
    `itemID` varchar(50) not null,
    constraint user_item_id_uindex
        unique (userID, itemID)
);

create table user_abilities
(
    `userID`    int auto_increment primary key,
    `abilityID` varchar(50) not null,
    constraint user_ability_id_uindex
        unique (userID, abilityID)
);

create view boss_info as
SELECT b.id,
       b.name                                                                    as boss,
       concat('{', group_concat(DISTINCT concat('"', s.name, '"'), ':', bs.value), '}') as stats
from bosses as b
         LEFT JOIN boss_stats as bs on b.id
         LEFT JOIN stats as s on s.id = bs.statID
GROUP BY b.name;

create view user_info as
SELECT u.id    as userID,
       u.name  as user,
       u.level,
       u.bossNo,
       a.id    as abilityID,
       a.name  as ability,
       a.damage,
       a.scale,
       s.id    as statID,
       s.name  as stat,
       ro.id   as rarityID,
       ro.name as rarity,
       ro.probability
FROM users as u
         LEFT JOIN user_abilities as ua ON ua.userID = u.id
         LEFT JOIN abilities as a on ua.abilityID = a.id
         LEFT JOIN stats as s on s.id = a.statID
         LEFT JOIN rarity_odds as ro on ro.id = a.rarityID
GROUP BY u.id, a.id;
